//
// Created by richard on 2018-09-16.
//

#pragma once

#include <algorithm>
#include "register_support.h"

namespace sim {

    /**
     * @brief Default implementation of is_slice_spec
     * @tparam T
     */
    template<typename T>
    struct is_slice_spec : std::false_type {
    };

    /**
     * @brief Implementation of is_slice_spec_v
     * @tparam T
     */
    template<typename T>
    inline constexpr bool is_slice_spec_v = is_slice_spec<T>::value;

    /**
     * @brief Default implementation of is_slice
     * @tparam T
     */
    template <typename T>
    struct is_slice : std::false_type {
    };

    /**
     * @brief Implementation of is_slice_v
     * @tparam T
     */
    template <typename T>
    inline constexpr bool is_slice_v = is_slice<T>::value;

    /**
     * @brief Default implementation of is_slice_accessor
     * @tparam T
     */
    template<typename T>
    struct is_slice_accessor : std::false_type {
    };

    /**
     * @brief Implementation of is_slice_accessor_v
     * @tparam T
     */
    template<typename T>
    inline constexpr bool is_slice_accessor_v = is_slice_accessor<T>::value;

    /**
     * @brief A type that specifies the parameters of a register slice.
     * @tparam start_bit The lowest bit in the slice.
     * @tparam end_bit The highest bit in the slice.
     * @tparam high_to_low True if bits are number high to low left to right
     * @tparam zero_index One past the bit that corresponds to bit zero. Only used if high_to_low is false
     */
    template<int start_bit, int end_bit, bool high_to_low = true, int zero_index = 0>
    struct slice_spec {
        /**
         * @brief Compute the effective start bit index of the slice.
         * @return The start bit index
         */
        static constexpr int _start_index() { return std::min(start_bit, end_bit); }

        /**
         * @brief Compute the effective end bit index of the slice.
         * @return The end bit index
         */
        static constexpr int _end_index() { return std::max(start_bit, end_bit); }

        static constexpr int start_index = high_to_low ? _start_index() : zero_index - 1 - _end_index();
        static constexpr int end_index = high_to_low ? _end_index() : zero_index - 1 - _start_index();

        static_assert(start_index >= 0 && end_index >= start_index, "Invalid effective bit indicies.");

        static constexpr int width = end_index - start_index + 1;

        typedef typename required_base_type<required_base_size<end_index+1>(), true>::base_type base_type_t;

        static constexpr auto mask() { return (((1U << width) - 1) << start_index); }
        static constexpr auto inv_mask() { return (~(((1U << width) - 1) << start_index)); }
    };

    template<int start_bit, int end_bit, bool high_to_low, int zero_index>
    struct is_slice_spec<slice_spec<start_bit, end_bit, high_to_low, zero_index>> : std::true_type {
    };

    /**
     * @brief A slice is a -- usually temporary -- value of a slice extracted from a register
     * @tparam SliceSpec specifies the slice parameters
     */
    template<typename SliceSpec>
    struct slice {
        typedef SliceSpec slice_spec_t;
        typedef typename SliceSpec::base_type_t base_type_t;

        base_type_t value;

        slice() = delete;

        /**
         * @brief Create a slice with a value
         * @tparam T The type of the initializing value
         * @param value The initializaing value
         */
        template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        explicit slice(T value) : value{static_cast<base_type_t>(value&SliceSpec::mask())} {}

        /**
         * @brief Combine two contiguous slices with a bitwise or operation
         * @tparam Slice The slice type of the other slice
         * @param other The other slice
         * @return A new slice
         */
        template <typename Slice, typename = typename std::enable_if_t<is_slice_v<Slice>>>
        auto operator|(const Slice other) {
            constexpr int start_index = std::min(SliceSpec::start_index, Slice::slice_spec_t::start_index);
            constexpr int end_index = std::max(SliceSpec::end_index, Slice::slice_spec_t::end_index);

            constexpr int mid_start_index = std::max(SliceSpec::start_index, Slice::slice_spec_t::start_index);
            constexpr int mid_end_index = std::min(SliceSpec::end_index, Slice::slice_spec_t::end_index);

            static_assert(mid_start_index - mid_end_index == 1, "Combined register slices must be contiguous.");

            typedef slice_spec<start_index,end_index> ReturnSliceSpec;
            return slice<ReturnSliceSpec>(value | other.value);
        }
    };

    template<typename SliceSpec>
    struct is_slice<slice<SliceSpec>> : std::true_type {};

    /**
     * @brief An accessor to get or set the value of a register slice.
     * @tparam RefBaseType The base type of the register value reference.
     * @tparam SliceSpec The specification of the slice.
     */
    template<typename RefBaseType, typename SliceSpec>
    struct slice_accessor {
        typedef RefBaseType base_type_t;
        typedef SliceSpec slice_spec_t;

        base_type_t &value;

        slice_accessor() = delete;

        explicit slice_accessor(base_type_t &value_ref) : value{value_ref} {}

        template<typename OtherSliceSpec>
        base_type_t mask_and_align(typename OtherSliceSpec::base_type_t other_value) {
            constexpr int left_shift = slice_spec_t::start_index - OtherSliceSpec::start_index;
            if constexpr (left_shift == 0) {
                return static_cast<base_type_t>(other_value & OtherSliceSpec::mask());
            }
            if constexpr (left_shift > 0) {
                return static_cast<base_type_t>((other_value & OtherSliceSpec::mask()) << left_shift);
            }
            if constexpr (left_shift < 0) {
                return static_cast<base_type_t>((other_value & OtherSliceSpec::mask()) >> -left_shift);
            }
        }

        template<typename OtherSliceSpec>
        base_type_t change_align() const {
            constexpr int left_shift = OtherSliceSpec::start_index - slice_spec_t::start_index;
            if constexpr (left_shift == 0) {
                return static_cast<typename OtherSliceSpec::base_type_t>(value & SliceSpec::mask());
            }
            if constexpr (left_shift > 0) {
                return static_cast<typename OtherSliceSpec::base_type_t>((value & SliceSpec::mask()) << left_shift);
            }
            if constexpr (left_shift < 0) {
                return static_cast<typename OtherSliceSpec::base_type_t>((value & SliceSpec::mask()) >> -left_shift);
            }
        }

        base_type_t masked_value() const {
            return value & slice_spec_t::mask();
        }

        base_type_t inv_masked_value() const {
            return value & slice_spec_t::inv_mask();
        }

        slice<SliceSpec> operator*() const {
            return slice<SliceSpec>(value & slice_spec_t::mask());
        }

        base_type_t operator()() const {
            return (value & slice_spec_t::mask()) >> slice_spec_t::start_index;
        }

        template <typename T, typename = typename std::enable_if_t<is_slice_accessor_v<T>>>
        int compare(T const &t) const {
            return operator()() - t.operator()();
        }

        template <typename T, typename = typename std::enable_if_t<is_slice_accessor_v<T>>>
        bool operator==(T const &t) const {
            return compare(t) == 0;
        }

        template <typename T, typename = typename std::enable_if_t<is_slice_accessor_v<T>>>
        bool operator!=(T const &t) const {
            return compare(t) != 0;
        }

        template<typename T, typename = typename std::enable_if_t<std::is_unsigned_v<T>>>
        slice_accessor &operator=(T t) {
            value = inv_masked_value() | ((t << slice_spec_t::start_index) & slice_spec_t::mask());
            return *this;
        }

        template<typename OtherSliceSpec>
        slice_accessor &operator=(const slice_accessor<base_type_t, OtherSliceSpec> &other) {
            static_assert(SliceSpec::width >= OtherSliceSpec::width, "Narrowing slice during assignment");
            value = inv_masked_value() | mask_and_align<OtherSliceSpec>(other.value);
            return *this;
        }

        template<typename OtherSliceSpec>
        slice_accessor &operator=(const slice<OtherSliceSpec> &other) {
            value = inv_masked_value() | mask_and_align<OtherSliceSpec>(other.value);
            return *this;
        }

        template <typename OtherSliceSpec, typename = typename std::enable_if_t<is_slice_spec_v<OtherSliceSpec>> >
        auto operator() (const OtherSliceSpec &spec) const {
            return slice<OtherSliceSpec>(change_align<OtherSliceSpec>());
        }

        explicit operator bool () const {
            return (value & SliceSpec::mask()) != 0;
        }

        template<typename T, typename = typename std::enable_if_t<std::is_unsigned_v<T>>>
        slice_accessor &operator+=(T t) {
            value = inv_masked_value() | ((masked_value() + ((t & slice_spec_t::mask()) << slice_spec_t::start_index)) &
                                          slice_spec_t::mask());
            return *this;
        }

        slice_accessor &operator++() { return operator+=(1U); }

        template<typename OtherSliceAccessor, typename = typename std::enable_if_t<is_slice_accessor_v<OtherSliceAccessor>>>
        slice_accessor &operator+=(const OtherSliceAccessor &other) {
            static_assert(SliceSpec::width >= OtherSliceAccessor::slice_spec_t::width, "Narrowing slice during assignment");
            value = inv_masked_value() |
                    ((masked_value() + mask_and_align<OtherSliceAccessor::slice_spec_t>(other.value)) &
                     slice_spec_t::mask());
            return *this;
        }

        template<typename T, typename = typename std::enable_if_t<std::is_unsigned_v<T>>>
        slice_accessor &operator-=(T t) {
            value = inv_masked_value() | ((masked_value() - ((t & slice_spec_t::mask()) << slice_spec_t::start_index)) &
                                          slice_spec_t::mask());
            return *this;
        }

        slice_accessor &operator--() { return operator-=(1U); }

        template<typename OtherSliceAccessor, typename = typename std::enable_if_t<is_slice_accessor_v<OtherSliceAccessor>>>
        slice_accessor &operator-=(const OtherSliceAccessor &other) {
            static_assert(SliceSpec::width >= OtherSliceAccessor::slice_spec_t::width, "Narrowing slice during assignment");
            value = inv_masked_value() |
                    ((masked_value() - mask_and_align<OtherSliceAccessor::slice_spec_t>(other.value)) &
                     slice_spec_t::mask());
            return *this;
        }

/*
        template<typename T, typename = typename std::enable_if_t<std::is_unsigned_v<T>>>
        slice_accessor &operator|=(T t) {
            value = (value | ((t & slice_spec_t::mask()) << slice_spec_t::start_index));
            return *this;
        }

        template<typename OtherSliceSpec>
        slice_accessor &operator|=(const slice_accessor<OtherSliceSpec> &other) {
            static_assert(SliceSpec::width >= OtherSliceSpec::width, "Narrowing slice during assignment");
            value = (value | mask_and_align<OtherSliceSpec>(other.value));
            return *this;
        }

        template<typename T, typename = typename std::enable_if_t<std::is_unsigned_v<T>>>
        slice_accessor &operator&=(T t) {
            value = (value | ((t & slice_spec_t::mask()) << slice_spec_t::start_index));
            return *this;
        }

        template<typename OtherSliceSpec>
        slice_accessor &operator&=(const slice_accessor<OtherSliceSpec> &other) {
            static_assert(SliceSpec::width >= OtherSliceSpec::width, "Narrowing slice during assignment");
            value = (value | mask_and_align<OtherSliceSpec>(other.value));
            return *this;
        }

        template<typename T, typename = typename std::enable_if_t<std::is_unsigned_v<T>>>
        slice_accessor &operator^=(T t) {
            value = (value ^ ((t & slice_spec_t::mask()) << slice_spec_t::start_index));
            return *this;
        }

        template<typename OtherSliceSpec>
        slice_accessor &operator^=(const slice_accessor<OtherSliceSpec> &other) {
            static_assert(SliceSpec::width >= OtherSliceSpec::width, "Narrowing slice during assignment");
            value = (value ^ mask_and_align<OtherSliceSpec>(other.value));
            return *this;
        }
*/
    };

    template<typename RefBaseType, typename SliceSpec>
    struct is_slice_accessor<slice_accessor<RefBaseType, SliceSpec>> : std::true_type {
    };
}