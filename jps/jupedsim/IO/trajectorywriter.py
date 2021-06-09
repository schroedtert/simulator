import pathlib
from abc import ABCMeta, abstractclassmethod, abstractmethod
from string import Template
from typing import List

from jpscore import Agent
from jpscore.geometry import LengthUnit, Units


class TrajectoryWriter(metaclass=ABCMeta):
    @abstractmethod
    def write_header(trajectory_file: pathlib.Path):
        raise NotImplementedError

    @abstractmethod
    def write_trajectory(trajectory_file, step: int, agents: List[Agent]):
        raise NotImplementedError


class SimpleTrajectoryWriter(TrajectoryWriter):
    row_template = Template("$frame $id $x $y $z\n")
    header = "frame ID x y z\n"

    def write_header(trajectory_file: pathlib.Path):
        """"""
        # frame ID x y z(lvl)
        with trajectory_file.open("w") as f:
            f.write(SimpleTrajectoryWriter.header)

    def write_trajectory(
        trajectory_file: pathlib.Path, step: int, agents: List[Agent]
    ):
        """"""
        with trajectory_file.open("a") as f:
            for agent in agents:
                row = SimpleTrajectoryWriter.row_template.substitute(
                    frame=step,
                    id=agent.id,
                    x=agent.pos.x.m,
                    y=agent.pos.y.m,
                    z=agent.pos.lvl.id,
                )
                f.write(row)
