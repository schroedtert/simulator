#include "geometry/length_unit.hpp"

auto main() -> int
{
    using namespace jps;
    using namespace details;

    scaleQuantity<Units::km, Units::um>(1);
    return 0;
}
