#include "spatial_vector_binding.hpp"

#include <geometry/spatial_vector.hpp>

void bind_spatial_vector(pybind11::module_ & m)
{
    pybind11::class_<jps::SpatialVector>(m, "SpatialVector")
        .def(pybind11::init<jps::LengthUnit, jps::LengthUnit>());
}
