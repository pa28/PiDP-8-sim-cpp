//
// Created by richard on 2018-09-16.
//

#pragma once

#include <type_traits>
#include <limits>
#include <cstdint>

namespace sim {

    template<int required_width, bool optimize_speed = true>
    struct required_base_type {
    };

    template<>
    struct required_base_type<std::numeric_limits<uint8_t>::digits, true> {
        typedef uint_fast8_t base_type;
    };

    template<>
    struct required_base_type<std::numeric_limits<uint8_t>::digits, false> {
        typedef uint_least8_t base_type;
    };

    template<>
    struct required_base_type<std::numeric_limits<uint16_t>::digits, true> {
        typedef uint_fast16_t base_type;
    };

    template<>
    struct required_base_type<std::numeric_limits<uint16_t>::digits, false> {
        typedef uint_least16_t base_type;
    };

    template<>
    struct required_base_type<std::numeric_limits<uint32_t>::digits, true> {
        typedef uint_fast32_t base_type;
    };

    template<>
    struct required_base_type<std::numeric_limits<uint32_t>::digits, false> {
        typedef uint_least32_t base_type;
    };

    template<>
    struct required_base_type<std::numeric_limits<uint64_t>::digits, true> {
        typedef uint_fast64_t base_type;
    };

    template<>
    struct required_base_type<std::numeric_limits<uint64_t>::digits, false> {
        typedef uint_least64_t base_type;
    };

    template<std::size_t bits>
    constexpr int required_base_size() {
        static_assert(bits <= std::numeric_limits<uint64_t>::digits, "Register size not supported.");
        if constexpr (bits <= std::numeric_limits<uint8_t>::digits)
            return std::numeric_limits<uint8_t>::digits;
        if constexpr (bits <= std::numeric_limits<uint16_t>::digits)
            return std::numeric_limits<uint16_t>::digits;
        if constexpr (bits <= std::numeric_limits<uint32_t>::digits)
            return std::numeric_limits<uint32_t>::digits;
        if constexpr (bits <= std::numeric_limits<uint64_t>::digits)
            return std::numeric_limits<uint64_t>::digits;
        else
            return 0;
    }

}