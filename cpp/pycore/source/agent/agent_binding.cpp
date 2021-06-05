#include "agent_binding.hpp"

#include <agent/agent.hpp>
#include <pybind11/operators.h>

void bind_agent(pybind11::module_ & m)
{
    pybind11::class_<jps::Agent>(m, "Agent")
        .def(pybind11::init<jps::Coordinate>())
        .def_property_readonly(
            "id", [](const jps::Agent & agent) -> unsigned int { return agent.getID(); })
        .def_readwrite("pos", &jps::Agent::pos)
        .def(
            "__str__",
            [](const jps::Agent & agent) { return fmt::format(FMT_STRING("{}"), agent); })
        .def("__repr__", [](const jps::Agent & agent) {
            return fmt::format(FMT_STRING("{}"), agent);
        });
}
