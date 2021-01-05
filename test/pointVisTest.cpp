#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pointVis.hpp>

TEST_CASE("Trivial test", "[trivial]") {
	REQUIRE((2+2) == 4);
}

TEST_CASE("addPoints test", "[pointVisTest]") {
	std::vector<std::array<double, PointVis::nDim>> points ({
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
		"White"
	});

	PointVis pv = PointVis();
	pv.addPoints(points);

	REQUIRE(pv.size() == points.size());
}
