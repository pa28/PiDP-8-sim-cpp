//
// Created by richard on 09/08/18.
//

#include <gtest/gtest.h>
#include "hardware.h"

using namespace sim;

TEST(Register, Definition) {
    hw_register<12> reg12{};
    hw_register<16> reg16{};
    hw_register<12, default_register_output_policy, register_store_policy<true,false>> least16{};

    EXPECT_EQ(12, reg12.storage_bits);
    EXPECT_EQ(07777, reg12.mask);

    EXPECT_EQ(16, reg16.storage_bits);
    EXPECT_EQ(0xFFFF, reg16.mask);

    EXPECT_EQ(16, least16.base_type_bits);
}

TEST(Register, Constructor) {
    hw_register<12> reg12_a{0x1234};
    hw_register<12> reg12_b{07777};

    hw_register<16> reg16_a{0x12345};
    hw_register<16> reg16_b{0xFFFF};

    EXPECT_EQ(0x234, reg12_a());
    EXPECT_EQ(07777, reg12_b());

    EXPECT_EQ(0x2345, reg16_a());
    EXPECT_EQ(0xFFFF, reg16_b());
}

TEST(Register, Operations_Size) {
    hw_register<12,default_register_output_policy, register_store_policy<true,false>> reg12_a{01234};
    hw_register<12,default_register_output_policy, register_store_policy<true,false>> reg12_b{07777};
    hw_register<12,default_register_output_policy, register_store_policy<true,false>> reg12_c{};
    hw_register<12,default_register_output_policy, register_store_policy<true,false>> reg12_d{01234};

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
    hw_register<12,default_register_output_policy, register_store_policy<true,true>> reg12_a{01234};
    hw_register<12,default_register_output_policy, register_store_policy<true,true>> reg12_b{07777};
    hw_register<12,default_register_output_policy, register_store_policy<true,true>> reg12_c{};
    hw_register<12,default_register_output_policy, register_store_policy<true,true>> reg12_d{01234};

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

TEST(Register, Slice) {
    hw_register<12> reg12_a{01234};
    hw_register<12> reg12_b{07777};
    hw_register<12> reg12_c{};
    hw_register<12> reg12_d{01234};

    // -------------------------------------
    // |11|10| 9| 8| 7| 6| 5| 4| 3| 2| 1| 0|
    // -------------------------------------

    hw_slice_spec<3,9> n3;
    hw_slice_spec<3,6> n2;
    hw_slice_spec<3,3> n1;
    hw_slice_spec<3,0> n0;

    hw_slice_spec<6,6> b1;
    hw_slice_spec<6,0> b0;

    EXPECT_EQ(1, reg12_a[n3]());
    EXPECT_EQ(2, reg12_a[n2]());
    EXPECT_EQ(3, reg12_a[n1]());
    EXPECT_EQ(4, reg12_a[n0]());

    reg12_a << (reg12_a[b1](b0) | reg12_a[b0](b1));
    EXPECT_EQ(03412, reg12_a());

    reg12_a << (reg12_a[b0](b1) | reg12_a[b1](b0));
    EXPECT_EQ(01234, reg12_a());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
