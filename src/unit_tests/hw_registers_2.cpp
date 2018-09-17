//
// Created by richard on 2018-09-15.
//

#include <gtest/gtest.h>
#include "register.h"

using namespace sim;

struct least_store_policy : sim::register_store_policy<true, false> {
};
struct fast_store_policy : sim::register_store_policy<true, true> {
};

template<int storage_size>
using least_register_t = hw_register<storage_size, default_register_output_policy, least_store_policy>;

template<int storage_size>
using fast_register_t = hw_register<storage_size, default_register_output_policy, fast_store_policy>;

TEST(Register, Definition) {

    fast_register_t<12> reg12{};
    fast_register_t<16> reg16{};
    least_register_t<12> least12{};

    EXPECT_EQ(12, reg12.storage_bits);
    EXPECT_EQ(07777, reg12.mask);

    EXPECT_EQ(16, reg16.storage_bits);
    EXPECT_EQ(0xFFFF, reg16.mask);

    EXPECT_LT(reg12.storage_bits, reg16.storage_bits);

    EXPECT_EQ(16, least12.base_type_bits);

    bool test = is_hw_register_v<hw_register<12,default_register_output_policy,least_store_policy>>;
    EXPECT_TRUE(test);
    test = is_hw_register_v<hw_register<16,default_register_output_policy,least_store_policy>>;
    EXPECT_TRUE(test);
    EXPECT_TRUE(is_hw_register_v<least_register_t<12>>);
    EXPECT_TRUE(is_hw_register_v<fast_register_t<12>>);
}

TEST(Register, Constructor) {
    least_register_t<12> reg12_a{0x1234};
    least_register_t<12> reg12_b{07777};

    fast_register_t<16> reg16_a{0x12345};
    fast_register_t<16> reg16_b{0xFFFF};

    EXPECT_EQ(0x234, reg12_a());
    EXPECT_EQ(07777, reg12_b());

    EXPECT_EQ(0x2345, reg16_a());
    EXPECT_EQ(0xFFFF, reg16_b());
}

TEST(Register, Operations_Size) {
    least_register_t<12> reg12_a{01234};
    least_register_t<12> reg12_b{07777};
    least_register_t<12> reg12_c{};
    least_register_t<12> reg12_d{01234};

    EXPECT_EQ(01234, reg12_a());
    EXPECT_EQ(07777, reg12_b());
    EXPECT_EQ(0, reg12_c());

    EXPECT_TRUE((bool)reg12_a);
    EXPECT_TRUE((bool)reg12_b);
    EXPECT_FALSE((bool)reg12_c);

    EXPECT_TRUE(reg12_a == reg12_d);
    EXPECT_FALSE(reg12_a == reg12_b);
    EXPECT_TRUE(reg12_a != reg12_b);
    EXPECT_FALSE(reg12_a != reg12_d);
    EXPECT_TRUE(reg12_a < reg12_b);
    EXPECT_FALSE(reg12_b < reg12_a);
    EXPECT_TRUE(reg12_a <= reg12_b);
    EXPECT_TRUE(reg12_a <= reg12_d);
    EXPECT_FALSE(reg12_a <= reg12_c);
}

TEST(Register, Operations_Speed) {
    fast_register_t<12> reg12_a{01234};
    fast_register_t<12> reg12_b{07777};
    fast_register_t<12> reg12_c{};
    fast_register_t<12> reg12_d{01234};

    EXPECT_EQ(01234, reg12_a());
    EXPECT_EQ(07777, reg12_b());
    EXPECT_EQ(0, reg12_c());

    EXPECT_TRUE((bool)reg12_a);
    EXPECT_TRUE((bool)reg12_b);
    EXPECT_FALSE((bool)reg12_c);

    EXPECT_TRUE(reg12_a == reg12_d);
    EXPECT_FALSE(reg12_a == reg12_b);
    EXPECT_TRUE(reg12_a != reg12_b);
    EXPECT_FALSE(reg12_a != reg12_d);
    EXPECT_TRUE(reg12_a < reg12_b);
    EXPECT_FALSE(reg12_b < reg12_a);
    EXPECT_TRUE(reg12_a <= reg12_b);
    EXPECT_TRUE(reg12_a <= reg12_d);
    EXPECT_FALSE(reg12_a <= reg12_c);
}

TEST(Register, Operations_Mixed) {
    {
        fast_register_t<12> reg12_a{01234};
        least_register_t<12> reg12_b{07777};
        least_register_t<12> reg12_c{};
        least_register_t<12> reg12_d{01234};

        EXPECT_EQ(01234, reg12_a());
        EXPECT_EQ(07777, reg12_b());
        EXPECT_EQ(0, reg12_c());

        EXPECT_TRUE((bool) reg12_a);
        EXPECT_TRUE((bool) reg12_b);
        EXPECT_FALSE((bool) reg12_c);

        EXPECT_TRUE(reg12_a == reg12_d);
        EXPECT_FALSE(reg12_a == reg12_b);
        EXPECT_TRUE(reg12_a != reg12_b);
        EXPECT_FALSE(reg12_a != reg12_d);
        EXPECT_TRUE(reg12_a < reg12_b);
        EXPECT_FALSE(reg12_b < reg12_a);
        EXPECT_TRUE(reg12_a <= reg12_b);
        EXPECT_TRUE(reg12_a <= reg12_d);
        EXPECT_FALSE(reg12_a <= reg12_c);
    }
    {
        least_register_t<12> reg12_a{01234};
        fast_register_t<12> reg12_b{07777};
        fast_register_t<12> reg12_c{};
        fast_register_t<12> reg12_d{01234};

        EXPECT_EQ(01234, reg12_a());
        EXPECT_EQ(07777, reg12_b());
        EXPECT_EQ(0, reg12_c());

        EXPECT_TRUE((bool) reg12_a);
        EXPECT_TRUE((bool) reg12_b);
        EXPECT_FALSE((bool) reg12_c);

        EXPECT_TRUE(reg12_a == reg12_d);
        EXPECT_FALSE(reg12_a == reg12_b);
        EXPECT_TRUE(reg12_a != reg12_b);
        EXPECT_FALSE(reg12_a != reg12_d);
        EXPECT_TRUE(reg12_a < reg12_b);
        EXPECT_FALSE(reg12_b < reg12_a);
        EXPECT_TRUE(reg12_a <= reg12_b);
        EXPECT_TRUE(reg12_a <= reg12_d);
        EXPECT_FALSE(reg12_a <= reg12_c);
    }
}

TEST(Register, Slice_Size) {
    least_register_t<12> reg12_a{01234};
    least_register_t<12> reg12_b{};

    // -------------------------------------
    // |11|10| 9| 8| 7| 6| 5| 4| 3| 2| 1| 0|
    // -------------------------------------

    slice_spec<9,11> n3;
    slice_spec<6,8> n2;
    slice_spec<3,5> n1;
    slice_spec<0,2> n0;

    [[maybe_unused]] slice_spec<6,11> b1;
    [[maybe_unused]] slice_spec<0,5> b0;

    EXPECT_EQ(01000, (*reg12_a[n3]).value);
    EXPECT_EQ(00200, (*reg12_a[n2]).value);
    EXPECT_EQ(00030, (*reg12_a[n1]).value);
    EXPECT_EQ(00004, (*reg12_a[n0]).value);

    reg12_a = reg12_a[b1](b0) | reg12_a[b0](b1);
    EXPECT_EQ(03412, reg12_a());

    reg12_a = reg12_a[b1](b0) | reg12_a[b0](b1);
    EXPECT_EQ(01234, reg12_a());

    reg12_b = reg12_a[n1](n1);
    EXPECT_EQ(00030, reg12_b());

    reg12_b = 0;
    EXPECT_EQ(0, reg12_b());

    [[maybe_unused]] auto sla0 = reg12_a[n0];
    [[maybe_unused]] auto sla1 = reg12_a[n1];
    [[maybe_unused]] auto slab = reg12_a[b0];

    reg12_b = 07;

    auto slb0 = reg12_b[n0];
    auto slb1 = reg12_b[n1];

    EXPECT_TRUE(sla0);
    EXPECT_FALSE(slb1);
    ++sla0;
    EXPECT_EQ(01235, reg12_a());
    sla0 += 3U;
    EXPECT_EQ(01230, reg12_a());
    --sla0;
    EXPECT_EQ(01237, reg12_a());
    sla0 -= 3U;
    EXPECT_EQ(01234, reg12_a());
    ++slb0;
    EXPECT_EQ(0, reg12_b());
    --slb0;
    EXPECT_EQ(7, reg12_b());
    EXPECT_EQ(sla0, sla0);
    EXPECT_NE(sla1, sla0);

    reg12_a = reg12_b;
    EXPECT_EQ(07, reg12_a());

    hw_register<12> instruction;
    slice_accessor<hw_register<12>::base_type, sim::slice_spec<04,04,false,12>> zero{instruction.value};
    zero = 1U;
    EXPECT_EQ(0200, instruction.value);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
