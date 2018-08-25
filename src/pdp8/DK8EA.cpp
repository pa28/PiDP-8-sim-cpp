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

        clk_flags = CLK_INT_FUNDAMENTAL;
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
            seed = (uint32_t) time(nullptr);

        generator.seed(seed);

        clk_flags = CLK_INT_FUNDAMENTAL;
    }

    void DK8EA::stop(device_bus &bus) {

    }

    void DK8EA::tick(device_bus &bus) {
        switch (clk_mode) {
            case DK8EA_Mode_A:
                /**
                 * In mode A, each time a tick occurs the device done flag is raised and, if device interrupts
                 * are enabled an interrupt request is raised.
                 */
                clk_flags |= (CLK_FLAG_FUNDAMENTAL);
                bus.set_device_done();
                break;
            case DK8EA_Mode_P:
                /**
                 * In mode P, if CLK_INT_FUNDAMENTAL then CLK_FLAG_FUNDAMENTAL is raised; then, the device done flag
                 * is raised and, if device interrupts are enabled an interrupt request is raised.
                 */
                if (clk_flags & CLK_INT_FUNDAMENTAL) {
                    clk_flags |= (CLK_FLAG_FUNDAMENTAL);
                    bus.set_device_done();
                } else if (clk_flags & CLK_OPR_SEQ) {
                    /**
                     * If not CLK_INT_FUNDAMENTAL but CLK_OPR_SEQ, on each tick clk_ctr0 is decremented until it
                     * is zero at which point CLK_FLAG_BASE and device done flags are raised (possibly resulting
                     * in an interrupt).
                     *
                     * When clk_ctr0 is 0 and clk_ctr1 is 0, both counters are reloaded from respective buffers.
                     *
                     * When clk_ctr0 is 0 and clk_ctr1 is not 0, clk_ctr1 is decremented. When clk_ctr1 becomes 0
                     * CLK_FLAG_MULT and device done flags are raised (possibly resulting in an interrupt).
                     *
                     * This allows the clock to produce a variable duty cycle operation between occurrences of
                     * CLK_FLAG_BASE and CLK_FLAG_MULT.
                     */
                    if (clk_ctr0 == 0) {
                        if (clk_ctr1 == 0) {
                            clk_ctr0 = clk_buf0;                    /* reload base counter */
                            clk_ctr1 = clk_buf1;                    /* reload multiplier */
                        } else {
                            clk_ctr1--;
                            if (clk_ctr1 == 0) {
                                if (clk_flags & CLK_INT_MULT) {
                                    clk_flags |= (CLK_FLAG_MULT);
                                    bus.set_device_done();
                                }
                            }
                        }
                    } else {
                        clk_ctr0--;
                        if (clk_ctr0 == 0) {
                            if (clk_flags & CLK_INT_BASE) {
                                clk_flags |= (CLK_FLAG_BASE);
                                bus.set_device_done();
                            }
                        }
                    }
                } else {
                    /**
                     * If not CLK_INT_FUNDAMENTAL and not CLK_OPR_SEQ:
                     *
                     * If clk_ctr0 is 0 and CLK_INT_BASE is set CLK_FLAG_BASE and device done flags are raised
                     * (possibly resulting in an interrupt).
                     *
                     * If clk_ctr0 is 0 and clk_ctr1 is 0 and CLK_INT_MULT is set CLK_FLAG_MULT and device done flags
                     * are raised (possibly resulting in an interrupt). Regardless of CLK_INT_MULT clk_ctr0 and
                     * clk_ctr1 are reloaded from respective buffers.
                     *
                     * If clk_ctr1 is not 0 it is decremented.
                     *
                     * If clk_ctr0 is not 0 it is decremented.
                     *
                     * This allows the clock to produce a repeating signal of CLK_FLAG_BASE at an interval of clk_buf0
                     * and CLK_FLAG_MULT at an interval of clk_buf0 * clk_buf1.
                     */
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
                            bus.clr_device_enable();
                            bus.clr_device_done();
                            bus.skip = true;
                            return data;
                        }
                        return data;

                    case 5:                                             /* CLLE */
                        if (data & 1)                                   /* test data<11> */
                            bus.set_device_enable();
                        else
                            bus.clr_device_enable().clr_device_done();
                        return data;

                    case 6:                                             /* CLCL */
                        bus.clr_device_enable();
                        return data;

                    case 7:                                             /* CLSK */
                        bus.skip = bus.is_device_done();
                        return data;

                    default:
                        return data;
                }                                               /* end switch */
            case DK8EA_Mode_P:                                      /* DK8EAPi */

                switch (command) {                                      /* decode IR<9:11> */
                    base_type tmp;

                    /**
                     * CLSF 060x0
                     *
                     * Set clk_flags to the low order six bits of AC.
                     */
                    case 0:                                             /* CLSF */
                        clk_flags = static_cast<uint32_t>(data & 077);  /* Set programmable flags */
                        break;

                        /**
                         * CLEI 060x1
                         *
                         * Enable device interrupts.
                         */
                    case 1:
                        bus.set_device_enable();
                        break;

                        /**
                         * CLDI 060x2
                         *
                         * Disable device interrupts.
                         */
                    case 2:
                        bus.clr_device_enable();
                        break;

                        /**
                         * CLSC
                         *
                         * Skip if device done flag is set, clear the device done flag.
                         */
                    case 3:
                        if (bus.is_device_done()) {
                            bus.clr_device_done();
                            bus.skip = true;
                        }
                        break;

                        /**
                         * CLSI
                         *
                         * Set clk_buf0 value, return the old value.
                         */
                    case 4:
                        tmp = static_cast<base_type>(clk_buf0);
                        clk_buf0 = data;
                        clk_ctr0 = data;
                        data = tmp;
                        break;

                        /**
                         * CLSM
                         *
                         * Set clk_buf1 value, return the old value.
                         */
                    case 5:
                        tmp = static_cast<base_type>(clk_buf1);
                        clk_buf1 = data;
                        clk_ctr1 = data;
                        data = tmp;
                        break;

                        /**
                         * RAND
                         *
                         * Return a random value in the AC
                         */
                    case 6:
                        if (clk_rand == 0) {
                            auto rnd = distribution(generator);
                            data = static_cast<base_type>(rnd & 07777);
                        } else {
                            data = static_cast<base_type>(rand_r(&seed) & 07777);
                        }
                        break;

                        /**
                         * CLRF
                         *
                         * Return clock flags in AC
                         */
                    case 7:
                        data = static_cast<base_type >(clk_flags & 07777);
                        clk_flags = static_cast<uint32_t>(data & 00077);
                        break;

                    default: // LCOV_EXCL_LINE
                        break; // LCOV_EXCL_LINE
                }                                               /* end switch */
        }

        return data;
    }
} // namespace pdp8
