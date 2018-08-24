//
// Created by richard on 06/08/18.
//

#ifndef CPU_SIM_DK8EA_H
#define CPU_SIM_DK8EA_H

#include <random>
#include "device.h"

namespace pdp8 {

    /**
     * DK8EA op codes and suggested mnemonics by mode:
     * Instruction description            Mode A    Mode P    Op Code
     * ===========================================================================
     * Set programmable flags                       CLSF      06050
     * Enable interrupt                   CLEI      CLEI      06051
     * Disable interrupt                  CLDI      CLDI      06052
     * Skip and disable on clock flag     CLSC      CLSC      06053
     * Set clock counter 0                          CLSI      06054
     * Set clock counter 1                          CLSM      06055
     * Clock enable on AC LS bit          CLLE                06055
     * Put random work in AC                        RAND      06056
     * Disable interrupt                  CLCL                06056
     * Skip if device done                CLSK                06057
     */

    class DK8EA {
    public:
        using clock_register_t = register_t;

        DK8EA() : hwrng{-1},
                  seed{0},
                  clk_mode{DK8EA_Mode_P},
                  clk_rand{DK8EA_HWRNG},
                  clk_buf0{0U},
                  clk_buf1{0U},
                  clk_flags{0},
                  clk_ctr0{0},
                  clk_ctr1{0},
                  distribution{},
                  generator{} {}

        void initialize(device_bus &bus);

        void reset(device_bus &bus);

        void stop(device_bus &bus);

        void tick(device_bus &bus);

        base_type dispatch(device_bus &bus, base_type command, base_type data);

        std::string name() const { return std::string{"clk"}; }

        std::string long_name() const { return std::string{"DK8-EAp"}; }

        enum DK8EA_Flags {
            CLK_INT_FUNDAMENTAL = 0001,
            CLK_INT_BASE = 0002,
            CLK_INT_MULT = 0004,
            CLK_OPR_SEQ = 0010,
            CLK_FLAG_FUNDAMENTAL = 0100,
            CLK_FLAG_BASE = 0200,
            CLK_FLAG_MULT = 0400,
        };

        enum DK8EA_Constants {
            DK8EA_Mode_A = 0,
            DK8EA_Mode_P = 1,
            DK8EA_PRNG = 0,
            DK8EA_HWRNG = 1,
        };

        int hwrng;                                                /* file descriptor of the hardware random number generator */
        inline static std::string hwrngPath = "/dev/random";      /* the path name of the hardware random number generator */
        uint32_t seed;                                            /* random seed */

        int32_t clk_mode;
        int32_t clk_rand;

    protected:
        uint32_t clk_buf0, clk_buf1;
        uint32_t clk_flags, clk_ctr0, clk_ctr1;

        std::uniform_int_distribution<base_type> distribution;
        std::mt19937 generator;
    };

    using DK8EA_p = std::unique_ptr<DK8EA>;

} // namespace pdp8


#endif //CPU_SIM_DK8EA_H
