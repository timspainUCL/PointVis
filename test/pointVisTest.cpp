#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pointVis.hpp>

TEST_CASE("Trivial test", "[trivial]") {
	REQUIRE((2+2) == 4);
}
