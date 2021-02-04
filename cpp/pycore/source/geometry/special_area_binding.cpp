#include "special_area_binding.hpp"

#include <geometry/special_area.hpp>

void bind_special_area(pybind11::module_ & m)
{
    pybind11::class_<jps::SpecialArea>(m, "SpecialArea")
        .def(pybind11::init<jps::Area, std::uint32_t>());
}
