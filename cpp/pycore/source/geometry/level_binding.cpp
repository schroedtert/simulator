#include "level_binding.hpp"

#include <geometry/level.hpp>

void bind_level(pybind11::module_ & m)
{
    pybind11::class_<jps::Level>(m, "Level").def(pybind11::init<>());
}
