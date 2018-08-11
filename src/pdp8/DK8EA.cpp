//
// Created by richard on 06/08/18.
//

#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "DK8EA.h"

namespace pdp8 {

    void DK8EA::initialize(device_bus &bus) {
        clk_flags = clk_ctr0 = clk_ctr1 = 0;
        clk_buf0 = 0U;
        clk_buf1 = 0U;
    }

    void DK8EA::reset(device_bus &bus) {
        clk_flags = clk_ctr0 = clk_ctr1 = 0;

        bus.clr_device_done();                       /* clear done, int */
        bus.clr_device_enable();                     /* clear enable */

        if (hwrng < 0) {
            if (access(hwrngPath.c_str(), R_OK) == 0) {
                hwrng = open(hwrngPath.c_str(), O_RDONLY);
                read(hwrng, &seed, sizeof(seed));
                close(hwrng);
                hwrng = -1;
                clk_rand = 0;
            } else {
                hwrng = -1;
                clk_rand = 1;
                fprintf(stderr, "Can not access %s\n", hwrngPath.c_str());
            }
        }

        if (seed == 0)
            seed = (uint32_t)time(nullptr);

        generator.seed(seed);

        switch(clk_mode) {
            case 0:
                clk_flags = CLK_INT_FUNDAMENTAL;
                break;
            case 1:
                clk_flags = CLK_INT_MULT;
                break;
            default:
                break;
        }
    }

    void DK8EA::stop(device_bus &bus) {

    }

    void DK8EA::tick(device_bus &bus) {
        switch(clk_mode) {
            case 0:                                                 /* DK8EA */
                clk_flags |= (CLK_FLAG_FUNDAMENTAL);
                bus.set_device_done();
                break;
            case 1:                                                 /* DK8EAPi */
                if (clk_flags & CLK_INT_FUNDAMENTAL) {
                    clk_flags |= (CLK_FLAG_FUNDAMENTAL);
                    bus.set_device_done();
                }
                if (clk_flags & CLK_OPR_SEQ) {
                    if (clk_ctr0 == 0) {
                        if (clk_ctr1 == 0) {
                            clk_ctr0 = clk_buf0;                    /* reload base counter */
                            clk_ctr1 = clk_buf1;                    /* reload multiplier */
                        } else {
                            clk_ctr1--;
                            if (clk_ctr1 == 0) {
                                clk_flags |= (CLK_FLAG_MULT);
                                bus.set_device_done();
                            }
                        }
                    } else {
                        clk_ctr0--;
                        if (clk_ctr0 == 0) {
                            clk_flags |= (CLK_FLAG_BASE);
                            bus.set_device_done();
                        }
                    }
                } else {
                    if (clk_ctr0 == 0) {
                        if (clk_flags & CLK_INT_BASE) {
                            clk_flags |= (CLK_FLAG_BASE);
                            bus.set_device_done();
                        }
                        if (clk_ctr1 == 0) {
                            if (clk_flags & CLK_INT_MULT) {
                                clk_flags |= (CLK_FLAG_MULT);
                                bus.set_device_done();
                            }
                            clk_ctr0 = clk_buf0;                         /* reload base counter */
                            clk_ctr1 = clk_buf1;                         /* reload multiplier */
                        } else {
                            clk_ctr0 = clk_buf0;
                            clk_ctr1--;
                        }
                    } else {
                        clk_ctr0--;
                    }
                }
                break;
            default:
                break;
        }
    }

    base_type DK8EA::dispatch(device_bus &bus, base_type command, base_type data) {
        switch (clk_mode) {
            case DK8EA_Mode_A:                                      /* DK8EA */
                /* IOT routine
                   IOT's 6xx1-6xx3 are the PDP-8/E clock
                   IOT's 6xx5-6xx7 are the PDP-8/A clock
                */
                switch (command) {                                      /* decode IR<9:11> */

                    case 1:                                             /* CLEI */
                        bus.set_device_enable();
                        return data;

                    case 2:                                             /* CLDI */
                        bus.clr_device_enable();
                        return data;

                    case 3:                                             /* CLSC */
                        if (bus.is_device_done()) {                     /* flag set? */
                            bus.clr_device_enable( );
                            bus.skip = true;
                            return data;
                        }
                        return data;

                    case 5:                                             /* CLLE */
                        if (data & 1)                                   /* test data<11> */
                            bus.set_device_enable( );
                        else
                            bus.clr_device_enable( ).clr_device_done( );
                        return data;

                    case 6:                                             /* CLCL */
                        bus.clr_device_enable( );
                        return data;

                    case 7:                                             /* CLSK */
                        bus.skip = bus.is_device_done( );
                        return data;

                    default:
                        return data;
                }                                               /* end switch */
            case DK8EA_Mode_P:                                      /* DK8EAPi */
                /* IOT routine
                   IOT's 6xx1-6xx3 are the PDP-8/E clock
                   6xx4 CLSI    Set buffer and counter 0 from data, return data has old value
                   6xx5 CLSM    Set buffer and counter 1 from data, return data has old value
                   6xx6 RAND    Return a psuedo random number
                */

                switch (command) {                                      /* decode IR<9:11> */
                    base_type tmp;

                    case 0:                                             /* CLSF */
                        clk_flags = static_cast<uint32_t>(data & 077);  /* Set programmable flags */
                        return data;

                    case 1:                                             /* CLEI */
                        bus.set_device_enable();
                        return data;

                    case 2:                                             /* CLDI */
                        bus.clr_device_enable();
                        return data;

                    case 3:                                             /* CLSK */
                        if (bus.is_device_done()) {                     /* flag set? */
                            bus.clr_device_done();
                            bus.skip = true;
                            return data;
                        }
                        return data;

                    case 4:                                             /* CLSI */
                        tmp = clk_buf0;
                        clk_buf0 = data;
                        clk_ctr0 = data;
                        return tmp;

                    case 5:                                             /* CLSM */
                        tmp = clk_buf1;
                        clk_buf1 = data;
                        clk_ctr1 = data;
                        return tmp;

                    case 6:                                             /* RAND */
                        if (clk_rand == 0) {
                            auto rnd = distribution(generator);
                            data = static_cast<base_type>(rnd & 07777);
                        } else {
                            data = static_cast<base_type>(rand_r(&seed) & 07777);
                        }
                        return data;

                    case 7:                                             /* CLRF */
                        data = static_cast<base_type >(clk_flags & 07777);
                        clk_flags = static_cast<uint32_t>(data & 00077);
                        return data;

                    default:
                        return data;
                }                                               /* end switch */
            default:
                return data;
        }
    }
} // namespace pdp8
