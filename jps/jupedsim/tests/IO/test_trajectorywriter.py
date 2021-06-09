import re

import pytest
from jpscore import Agent, JPSGeometryException, Simulation
from jpscore.geometry import Coordinate, LengthUnit, Level, Units
from jupedsim.IO.trajectorywriter import (
    SimpleTrajectoryWriter,
    TrajectoryWriter,
)


def test_trajectorywriter_is_only_interface():
    file_path = "dummy"
    with pytest.raises(TypeError):
        can_not_instantiate = TrajectoryWriter()
    with pytest.raises(NotImplementedError):
        TrajectoryWriter.write_header(file_path)
    with pytest.raises(NotImplementedError):
        TrajectoryWriter.write_trajectory(file_path, 0, [])


def test_simpletrajectorywriter_writes_header_deletes_content_of_file(
    tmp_path,
):
    trajectory_txt = tmp_path / "trajectory.txt"
    with trajectory_txt.open("w") as f:
        f.write("This is some content which should be deleted")

    SimpleTrajectoryWriter.write_header(trajectory_txt)

    # TODO add test


def test_simpletrajectorywriter_writes_header(tmp_path):
    trajectory_txt = tmp_path / "trajectory.txt"

    SimpleTrajectoryWriter.write_header(trajectory_txt)

    # TODO add test


@pytest.mark.parametrize(
    "agents",
    [
        [],
        [
            Agent(
                Coordinate(
                    LengthUnit(0.1, Units.m),
                    LengthUnit(0, Units.m),
                    Level(-12),
                )
            ),
            Agent(
                Coordinate(
                    LengthUnit(21, Units.m), LengthUnit(12, Units.m), Level(1)
                )
            ),
        ],
    ],
)
def test_simpletrajectorywriter_writes_trajectories(tmp_path, agents):
    trajectory_txt = tmp_path / "trajectory.txt"

    SimpleTrajectoryWriter.write_trajectory(trajectory_txt, 0, agents)
    # TODO add test


@pytest.mark.parametrize(
    "agents",
    [
        [],
        [
            Agent(
                Coordinate(
                    LengthUnit(0.1, Units.m),
                    LengthUnit(0, Units.m),
                    Level(-12),
                )
            ),
            Agent(
                Coordinate(
                    LengthUnit(21, Units.m), LengthUnit(12, Units.m), Level(1)
                )
            ),
        ],
    ],
)
def test_simpletrajectorywriter_writes_complete_trajectory_file(
    tmp_path, agents
):
    trajectory_txt = tmp_path / "trajectory.txt"

    SimpleTrajectoryWriter.write_header(trajectory_txt)
    SimpleTrajectoryWriter.write_trajectory(trajectory_txt, 0, agents)

    # TODO add test
