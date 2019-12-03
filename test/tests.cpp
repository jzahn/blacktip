#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "src/mix.h"
#include "src/o2toxicity.h"

using namespace blacktip;

Mix mix = Mix::getMixAir();
O2Toxicity o2toxicity;

TEST_CASE( "O2Toxicity: 0 State" ) {
    REQUIRE( o2toxicity.getPO2() == 0.0 );
    REQUIRE( o2toxicity.getCNSToxicity() == 0.0 );
    REQUIRE( o2toxicity.getPulmonaryToxicity() == 0.0 );
}
