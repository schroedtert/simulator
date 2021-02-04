#include "area_binding.hpp"

#include <geometry/area.hpp>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

void bind_area(pybind11::module_ & m)
{
    pybind11::class_<jps::Area>(m, "Area").def(pybind11::init<std::vector<jps::Coordinate>>());
}
