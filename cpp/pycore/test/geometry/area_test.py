import pytest
from jpscore.geometry import Area, LineSegment, Coordinate, LengthUnit, Level


class TestArea:
    @pytest.mark.parametrize(
        "coordinates",
        [
        ],
    )
    def test_constructor_from_coordinates(self, coordinates):
        area = Area(coordinates)
        assert area.polygon == area
