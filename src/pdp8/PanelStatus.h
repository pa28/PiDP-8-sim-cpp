//
// Created by richard on 2018-08-26.
//

#pragma once

#include <array>
#include <iostream>
#include <netinet/in.h>
#include "pdp8.h"

namespace pdp8 {

    enum CPU_StatusState {
        Fetch, Defer, Execute, Running
    };

    enum PannelCommand {
        PanelStart,
        PanelLoadAddress,
        PanelDeposit,
        PanelExamine,
        PanelContinue,
        PanelStop,
        PanelUser0,
        PanelUser1,
    };

    template<size_t N>
    class PanelStatus {
    public:
        using word_type_t = memory_t;
        static constexpr size_t word_count = N;

        static constexpr sim::hw_slice_spec<12, 0> cpu_word{};
        static constexpr sim::hw_slice_spec<13, 0> ac_link{};
        static constexpr sim::hw_slice_spec<3, 12> pack_field{};
        static constexpr sim::hw_slice_spec<3, 0> field{};
        static constexpr sim::hw_slice_spec<10, 6> flags{};
        static constexpr sim::hw_slice_spec<1, 15> fl_fetch{};
        static constexpr sim::hw_slice_spec<1, 14> fl_exec{};
        static constexpr sim::hw_slice_spec<1, 13> fl_defer{};
        static constexpr sim::hw_slice_spec<1, 12> fl_word_count{};
        static constexpr sim::hw_slice_spec<1, 11> fl_cur_addr{};
        static constexpr sim::hw_slice_spec<1, 10> fl_break{};
        static constexpr sim::hw_slice_spec<1, 9> fl_ion{};
        static constexpr sim::hw_slice_spec<1, 8> fl_pause{};
        static constexpr sim::hw_slice_spec<1, 7> fl_run{};
        static constexpr sim::hw_slice_spec<1, 6> fl_idle{};
        static constexpr sim::hw_slice_spec<6, 0> step_counter{};


        std::array<word_type_t, word_count> data;

        PanelStatus() = default;

        std::ostream &serialize_raw(std::ostream &strm) {
            for (auto const &word : data) {
                auto sword = htons(word);
                strm.write(reinterpret_cast<const char *>(&sword), sizeof(sword));
            }
            return strm;
        }

        std::istream &deserialize_raw(std::istream &strm) {
            for (auto word : data) {
                word_type_t sword;
                strm.read(reinterpret_cast<char *>(&sword), sizeof(sword));
                word = ntohs(sword());
            }
            return strm;
        }
    };

    class PanelStatusLights : public PanelStatus<8> {
    public:
        PanelStatusLights() = default;

        /**
         * Contents of data array:
         * Program Counter     0:0-11
         * Memory Address      1:0-11
         * Memory Buffer       2:0-11
         * Link, Accumulator   3:0-12
         * Multiplier Quotient 4:0-11
         * Insr Field          0:12-14
         * Data Field          1:12-14
         * Instruction         2:12-14
         * Fetch               5:15
         * Execute             5:14
         * Defer               5:13
         * Word Count          5:12
         * Current Address     5:11
         * Break               5:10
         * ION                 5: 9
         * Pause               5: 8
         * Run                 5: 7
         * Idle Detection      5: 6
         * Step Counter        5: 0-5
         */

        void set_pc(word_type_t pc) { data[0] << pc[cpu_word](cpu_word); }

        void set_ma(word_type_t ma) { data[1] << ma[cpu_word](cpu_word); }

        void set_mb(word_type_t mb) { data[2] << mb[cpu_word](cpu_word); }

        void set_acl(word_type_t acl) { data[3] << acl[ac_link](ac_link); }

        void set_mq(word_type_t mq) { data[4] << mq[cpu_word](cpu_word); }

        void set_inst_field(word_type_t df) { data[0] << df[field](pack_field); }

        void set_data_field(word_type_t df) { data[1] << df[field](pack_field); }

        void set_instruction(word_type_t istr) { data[1] << istr[field](pack_field); }

        void
        set_flags(bool fetch, bool exec, bool defer, bool word_count, bool cur_addr, bool brk, bool ion, bool pause,
                  bool run, bool idle) {
            data[5] << flags.clear() << fl_fetch(fetch) << fl_exec(exec) << fl_defer(defer) << fl_word_count(word_count)
                    << fl_cur_addr(cur_addr) << fl_break(brk) << fl_ion(ion) << fl_pause(pause) << fl_run(run)
                    << fl_idle(idle);
        }

        void set_step_counter(word_type_t step_cnt) { data[5] << step_cnt[step_counter](step_counter); }

        auto get_acl() const { return data[3][ac_link](); }

        bool get_run_flag() const { return static_cast<bool>(data[5][fl_run]()); }
    };

    class PanelStatusSwitches : public PanelStatus<2> {
    public:
        PanelStatusSwitches() = default;

        /**
         * Contents of data array:
         * Switch Register      0:0-11
         * Data Field           1:9-11
         * Inst Field           1:6-8
         * Stepping State       1:4,5
         * Command              1:0-3
         */
    };

} // namespace pdp8
