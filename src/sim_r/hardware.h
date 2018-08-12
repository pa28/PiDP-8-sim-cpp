//
// Created by richard on 02/08/18.
//

#ifndef CPU_SIM_HARDWARE_H
#define CPU_SIM_HARDWARE_H


#include <cstddef>
#include <type_traits>
#include <limits>
#include <iostream>
#include <iomanip>

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

    template <bool _check_storage_size, bool _optimize_speed>
    struct register_store_policy {
        static constexpr bool check_storage_size = _check_storage_size;
        static constexpr bool optimize_speed = _optimize_speed;
    };

    struct default_register_store_policy : register_store_policy<true,true> {};

    template<typename T>
    struct is_hw_register : std::false_type {
    };

    template<typename T>
    inline constexpr bool is_hw_register_v = is_hw_register<T>::value;

    template<typename T>
    struct is_hw_slice_spec : std::false_type {
    };

    template<typename T>
    inline constexpr bool is_hw_slice_spec_v = is_hw_slice_spec<T>::value;

    template<typename T>
    struct is_hw_slice : std::false_type {
    };

    template<typename T>
    inline constexpr bool is_hw_slice_v = is_hw_slice<T>::value;

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

    template<size_t bits>
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

    template<typename T, size_t W, size_t O>
    struct hw_slice;

    template<size_t _width, size_t _offset>
    struct hw_slice_spec {
        static constexpr size_t width = _width;
        static constexpr size_t offset = _offset;
        typedef typename required_base_type<required_base_size<width + offset>()>::base_type base_type;

        auto clear() const {
            return hw_slice<base_type, width, offset>{0};
        }

        auto set() const {
            return hw_slice<base_type, width, offset>{((1 << width) - 1) << offset};
        }

        template<typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        auto operator()(T value) const {
            return hw_slice<base_type, width, offset>{(value & ((1 << width) - 1)) << offset};
        }
    };

    template<size_t _width, size_t _offset>
    struct is_hw_slice_spec<hw_slice_spec<_width, _offset>> : std::true_type {
    };

    template<size_t width, size_t offset_dest, size_t offset_source>
    struct differential_shift {
        static constexpr size_t shift = (offset_dest<offset_source ? offset_source-offset_dest : offset_dest-offset_source);
        template<typename T>
        auto operator()(T value) {
            if constexpr (offset_dest == offset_source) {
                return value;
            } else if (offset_dest < offset_source) {
//                auto s = offset_source;
//                auto d = offset_dest;
//                auto w = width;
//                auto sh = shift;
                typedef typename required_base_type<required_base_size<width + shift>()>::base_type rtype;
                return static_cast<rtype>(value) >> (shift);
            } else {
//                auto s = offset_source;
//                auto d = offset_dest;
//                auto w = width;
//                auto sh = shift;
                typedef typename required_base_type<required_base_size<width + shift>()>::base_type rtype;
                return static_cast<rtype>(value) << (shift);
            }
        }
    };

    template<int _storage_bits, typename _output_policy = default_register_output_policy,
            typename _store_policy = default_register_store_policy>
    struct hw_register;

    template<typename _storage, size_t _width, size_t _offset>
    struct hw_slice {
        typedef _storage base_type;
        static constexpr size_t width = _width;
        static constexpr size_t offset = _offset;
        static constexpr int storage_bits = std::numeric_limits<base_type>::digits;
        static constexpr base_type mask = ((1 << width) - 1) << offset;

        hw_slice() = default;

        explicit hw_slice(base_type init_value) : value{static_cast<base_type>(init_value & mask)} {}

        template<typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        explicit hw_slice(T const &other) {
            value = static_cast<base_type>(other.value & mask);
        }

        template<typename V, typename = typename std::enable_if_t<std::is_integral_v<V>>>
        explicit hw_slice(V init_value) {
            auto m = mask;
            value = static_cast<base_type>(init_value & mask);
        }

        base_type operator()() const {
            return value >> offset;
        }

        base_type value_in_place() const {
            return value;
        }

        explicit operator bool() const {
            return value != 0;
        }

        hw_slice &operator++() {
            value = (value + (1 << offset)) & mask;
            return *this;
        }

        hw_slice &operator--() {
            value = (value - (1 << offset)) & mask;
            return *this;
        }

        bool operator==(base_type v) const {
            return value == v;
        }

        bool operator!=(base_type v) const {
            return value != v;
        }

        hw_slice operator|(hw_slice<base_type, width, offset> const &other) const {
            return hw_slice<base_type, width, offset>{value | other.value};
        }

        template<typename T, typename = typename std::enable_if_t<is_hw_slice_v<T>>>
        auto operator|(T const &slice) const {
            constexpr size_t max_bit = std::max(width + offset, T::width + T::offset);
            constexpr size_t min_bit = std::min(offset, T::offset);
            constexpr size_t new_width = max_bit - min_bit;

            if constexpr (storage_bits >= T::storage_bits) {
                base_type rv = value_in_place() | static_cast<base_type>(slice.value_in_place());
                return hw_slice<base_type, new_width, min_bit>{rv};
            } else {
                typename T::base_type rv = slice.value_in_place() | static_cast<base_type>(value_in_place());
                return hw_slice<typename T::base_type, new_width, min_bit>{rv};
            }
        }

        hw_slice operator&(hw_slice<base_type, width, offset> const &slice) const {
            return hw_slice<base_type, width, offset>{value & slice.value};
        }

        hw_slice operator+(hw_slice<base_type, width, offset> const &slice) const {
            return hw_slice<base_type, width, offset>{value + slice.value};
        }

        hw_slice operator~() const {
            return hw_slice<base_type, width, offset>{~value};
        }

        template<typename T, typename = typename std::enable_if_t<is_hw_slice_spec_v<T>>>
        auto operator()(T const &slice_spec) const {
            typedef typename required_base_type<required_base_size<T::width + T::offset>()>::base_type new_base_type;
            differential_shift<T::width, T::offset, offset> ds{};
            return hw_slice<new_base_type, T::width, T::offset>{ds(value)};
        }

    protected:
        base_type value;
    };

    template<typename _storage, size_t _width, size_t _offset>
    struct is_hw_slice<hw_slice<_storage, _width, _offset>> : std::true_type {
    };

    template<int _storage_bits, typename _output_policy, typename _store_policy>
    struct hw_register {
        typedef _output_policy output_policy;
        typedef _store_policy store_policy;
        typedef typename required_base_type<required_base_size<_storage_bits>(),store_policy::optimize_speed>::base_type base_type;
        static constexpr int base_type_bits = std::numeric_limits<base_type>::digits;
        static constexpr int storage_bits = _storage_bits;
        static constexpr base_type mask = static_cast<base_type>((1 << storage_bits) - 1);

        hw_register() : value{0} {}

        template<typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        explicit hw_register(T const &other) : value{static_cast<base_type>(other() & mask)} {}

        template <typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        hw_register &operator=(T const &other) {
            static_assert(not store_policy::check_storage_size || (T::storage_bits <= storage_bits),
                          "Slice too wide for register storage.");
            static_assert(T::base_type_bits <= base_type_bits, "Slice too wide for register base type.");
            value = static_cast<base_type>(other.value);
            return *this;
        }

        template<typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        explicit hw_register(T init_value) : value{static_cast<base_type>(init_value & mask)} {}

        template<typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        hw_register &operator=(T v) {
            value = static_cast<base_type>(v & mask);
            return *this;
        }

        base_type operator()() const {
            return value;
        }

        template<typename T, typename = typename std::enable_if_t<is_hw_slice_spec_v<T>>>
        auto operator[](T const &slice_spec) const {
            static_assert(not store_policy::check_storage_size || ((T::width + T::offset) <= storage_bits),
                          "Slice too wide for register storage.");
            static_assert((T::width + T::offset) <= base_type_bits, "Slice too wide for register base type.");
            typedef typename required_base_type<required_base_size<T::width + T::offset>()>::base_type new_base_type;

            return hw_slice<new_base_type, T::width, T::offset>{value};
        }

        template<typename T, typename = typename std::enable_if_t<is_hw_slice_v<T>>>
        hw_register &operator<<(T const &slice) {
            static_assert(not store_policy::check_storage_size || ((T::width + T::offset) <= storage_bits),
                          "Slice too wide for register storage.");
            static_assert((T::width + T::offset) <= base_type_bits, "Slice too wide for register base type.");
            value = (value & ~static_cast<base_type>(T::mask)) | (slice.value_in_place());
        }

        std::ostream &print_on(std::ostream &ostream) const {
            return ostream << std::setbase(output_policy::radix)
                           << std::setw(output_policy::width)
                           << std::setfill(output_policy::fill)
                           << value
                           << std::dec;
        }

        template <typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator==(T const &other) const {
            return value == other.value;
        }

        template <typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator!=(T const &other) const {
            return value != other.value;
        }

        template <typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator<(T const &other) const {
            return value < other.value;
        }

        template <typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator>(T const &other) const {
            return value > other.value;
        }

        template <typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator<=(T const &other) const {
            return value <= other.value;
        }

        template <typename T, typename = typename std::enable_if_t<is_hw_register_v<T>>>
        bool operator>=(T const &other) const {
            return value >= other.value;
        }

        explicit operator bool() {
            return value != 0;
        }

    protected:
        base_type value;
    };

    template<int bits, typename out_pol, typename store_pol>
    struct is_hw_register<hw_register<bits, out_pol, store_pol>> : std::true_type {
    };

} // namespace sim

#endif //CPU_SIM_HARDWARE_H
