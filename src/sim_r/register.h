//
// Created by richard on 2018-09-16.
//

#pragma once

#include <type_traits>
#include "register_support.h"
#include "register_slice.h"

namespace sim {

    template<int _radix = 16, int _width = 0, char _fill = '\0', bool _show_base = false>
    struct register_output_policy {
        static constexpr int radix = _radix;
        static constexpr int width = _width;
        static constexpr char fill = _fill;
        static constexpr bool show_base = _show_base;
    };

    struct default_register_output_policy : register_output_policy<> {
    };

    template<bool _check_storage_size, bool _optimize_speed>
    struct register_store_policy {
        static constexpr bool check_storage_size = _check_storage_size;
        static constexpr bool optimize_speed = _optimize_speed;
    };

    struct default_register_store_policy : register_store_policy<true, true> {
    };

    template<typename T>
    struct is_hw_register : std::false_type {
    };

    template<typename T>
    inline constexpr bool is_hw_register_v = is_hw_register<T>::value;

    template<int _storage_bits,
            typename _output_policy = default_register_output_policy,
            typename _store_policy = default_register_store_policy>
    struct hw_register {
        typedef _output_policy output_policy;
        typedef _store_policy store_policy;
        typedef typename required_base_type<required_base_size<_storage_bits>(),
                store_policy::optimize_speed>::base_type base_type;
        static constexpr int base_type_bits = std::numeric_limits<base_type>::digits;
        static constexpr int storage_bits = _storage_bits;
        static constexpr base_type mask = static_cast<base_type>((1 << storage_bits) - 1);

        hw_register() : value{0} {}

        base_type operator()() const {
            return value & mask;
        }

        template<typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        explicit hw_register(T init_value) : value{static_cast<base_type>(init_value & mask)} {}

        template<typename T, typename = typename std::enable_if_t<std::is_integral_v<T> || is_slice_v<T>>>
        hw_register &operator=(T v) {
            if constexpr (std::is_integral_v<T>) {
                value = static_cast<base_type>(v & mask);
            }
            if constexpr (is_slice_v<T>) {
                value = static_cast<base_type>(v.value & mask);
            }
            return *this;
        }

        template<typename SliceSpec, typename = typename std::enable_if_t<is_slice_spec_v<SliceSpec>>>
        slice_accessor<base_type, SliceSpec> operator[](SliceSpec sliceSpec) {
            return slice_accessor<base_type, SliceSpec>{value};
        }

        template<typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator==(T const &other) const {
            return value == other.value;
        }

        template<typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator!=(T const &other) const {
            return value != other.value;
        }

        template<typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator<(T const &other) const {
            return value < other.value;
        }

        template<typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator>(T const &other) const {
            return value > other.value;
        }

        template<typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator<=(T const &other) const {
            return value <= other.value;
        }

        template<typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator>=(T const &other) const {
            return value >= other.value;
        }

        explicit operator bool() {
            return value != 0;
        }

        base_type value;
    };

    template<int bits, typename out_pol, typename store_pol>
    struct is_hw_register<hw_register<bits, out_pol, store_pol>> : std::true_type {
    };
}
