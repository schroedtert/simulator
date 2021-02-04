#include "line_segment_binding.hpp"

#include <geometry/line_segment.hpp>

void bind_line_segment(pybind11::module_ & m)
{
    pybind11::class_<jps::LineSegment>(m, "LineSegment")
        .def(pybind11::init<jps::Coordinate, jps::Coordinate>());
}
