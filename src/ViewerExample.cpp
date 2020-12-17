#include "PointsViewer.h"

#include <iostream>

int main(void)
{
	std::vector<std::array<double, PointsViewer::nDim>> points ({
			{1.0, 1, 1},
			{-1, 1, 1},
			{1, -1, 1},
			{-1, -1, 1},
			{1, 1, -1},
			{-1, 1, -1},
			{1, -1, -1},
			{-1, -1, -1},
			{1, 0, 0},
			{-1, 0, 0},
			{0, 1, 0},
			{0, -1, 0},
			{0, 0, 1},
			{0, 0, -1}
	});

	std::vector<std::string> colours({
		"White",
		"Red",
		"Green",
		"Blue"
	});

	PointsViewer v = PointsViewer();
	v.addPoints(points);
	v.setColours(colours);
	std::cout << v.size() << std::endl;

	return v.run();
}
