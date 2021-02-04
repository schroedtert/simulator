#include "coordinate_binding.hpp"

#include <geometry/coordinate.hpp>

void bind_coordinate(pybind11::module_ & m)
{
    pybind11::class_<jps::Coordinate>(m, "Coordinate")
        .def(pybind11::init<jps::LengthUnit, jps::LengthUnit, jps::Level>());
}
