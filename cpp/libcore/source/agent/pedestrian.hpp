#pragma once

#include "geometry/coordinate.hpp"
#include "geometry/length_unit.hpp"
#include "util/identifiable.hpp"

namespace jps
{
struct Pedestrian : public Identifiable<Pedestrian> {
    // NOLINTNEXTLINE
    Coordinate pos{0_m, 0_m, jps::Level{1}};

    explicit Pedestrian(Coordinate p_coordinate) : pos(p_coordinate){};

    auto operator==(Pedestrian const & p_other) const noexcept -> bool
    {
        return getID() == p_other.getID();
    }
    auto operator!=(Pedestrian const & p_other) const noexcept -> bool
    {
        return !(*this == p_other);
    }
};

} // namespace jps

namespace fmt
{
template <>
struct formatter<jps::Pedestrian> {
    template <typename ParseContext>
    constexpr auto parse(ParseContext & p_ctx)
    {
        return p_ctx.begin();
    }

    template <typename FormatContext>
    auto format(jps::Pedestrian const & p_ped, FormatContext & p_ctx)
    {
        return format_to(p_ctx.out(), "PED {:d}:({})", p_ped.getID(), p_ped.pos);
    }
};
} // namespace fmt