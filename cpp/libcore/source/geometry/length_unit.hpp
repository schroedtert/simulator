#pragma once

#include "enum.hpp"
#include "math/int_pow.hpp"

#include <cstdint>
#include <type_traits>

namespace jps
{
/// Enumeration for supported length units.
/// Underlying integer must be set to the decimal exponent relative to meter (like SI).
enum class Units { mum = -6, mm = -3, cm = -2, dm = -1, m = 0, km = 3 };
const int DECIMAL_BASE = 10;

namespace details
{
/// Scales the given quantity of a length unit from `from` unit to `to` unit.
/// The used  quantity type T can be deduced automatically.
/// If from < to the quantity is divided and truncated towards zero for integral T.
/// Integer overflow is not checked.
/// Can be called like: `scaleQuantity<Units::mm, Units::cm>(10)`
/// @tparam T should be of integral type
template <Units from, Units to, typename T>
constexpr T scaleQuantity(T p_quantity)
{
    static_assert(std::is_integral_v<T>, "T in scaleQuantity() should be of integral type.");

    const int diff_exp = toUnderlying(from) - toUnderlying(to);

    if constexpr(diff_exp < 0) {
        return p_quantity / jps::math::intPow<T, DECIMAL_BASE, -diff_exp>();
    } else {
        return p_quantity * jps::math::intPow<T, DECIMAL_BASE, diff_exp>();
    }
}

template <typename QuantityType, Units Unit>
struct LengthUnitParams {
    const QuantityType quantity; // NOLINT(misc-non-private-member-variables-in-classes)

    LengthUnitParams()                                 = delete;
    LengthUnitParams(LengthUnitParams const & p_other) = delete;
    LengthUnitParams & operator=(LengthUnitParams const & p_other) = delete;

    LengthUnitParams(LengthUnitParams && p_other) noexcept = default;
    LengthUnitParams & operator=(LengthUnitParams && p_other) noexcept = default;

    ~LengthUnitParams() = default;

    LengthUnitParams(QuantityType p_quantity) : quantity{p_quantity} {}
};
} // namespace details

class LengthUnit
{
public:
    using QuantityType = std::int_least64_t;

    const static Units RESOLUTION = Units::mum;

    LengthUnit() = default;

    LengthUnit(LengthUnit const & p_other) = default;
    LengthUnit & operator=(LengthUnit const & p_other) = default;

    LengthUnit(LengthUnit && p_moved) noexcept = default;
    LengthUnit & operator=(LengthUnit && p_moved) noexcept = default;

    ~LengthUnit() = default;

    template <Units Unit>
    LengthUnit(details::LengthUnitParams<QuantityType, Unit> const & p_params) :
        m_quantity{details::scaleQuantity<Unit, RESOLUTION>(p_params.quantity)}
    {
    }

    bool operator==(QuantityType p_other) const { return m_quantity == p_other; }

    template <Units unit = RESOLUTION>
    QuantityType get() const
    {
        return details::scaleQuantity<RESOLUTION, unit>(m_quantity);
    }

private:
    // Stores the length unit quantity in micro meter
    QuantityType m_quantity{};
};

template <Units Unit>
LengthUnit makeLengthUnit(LengthUnit::QuantityType p_quantity)
{
    return LengthUnit{details::LengthUnitParams<LengthUnit::QuantityType, Unit>{p_quantity}};
}

} // namespace jps