#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "src/mix.h"
#include "src/o2toxicity.h"

using namespace blacktip;

Mix air = Mix::getMixAir();
Mix ean32 = Mix::getMixEan32();
Mix ean36 = Mix::getMixEan36();

O2Toxicity o2toxicity;

TEST_CASE( "O2Toxicity: 0 State" ) {
    REQUIRE( o2toxicity.getPO2() == 0.0 );
    REQUIRE( o2toxicity.getCNSToxicity() == 0.0 );
    REQUIRE( o2toxicity.getPulmonaryToxicity() == 0.0 );
}

TEST_CASE( "O2Toxicity: P02" ) {
    o2toxicity.calculate(0, 0.0, air);
    REQUIRE( o2toxicity.getPO2() == 0.21 );
    o2toxicity.calculate(0, 0.0, ean32);
    REQUIRE( o2toxicity.getPO2() == 0.32 );
    o2toxicity.calculate(0, 0.0, ean36);
    REQUIRE( o2toxicity.getPO2() == 0.36 );
}

TEST_CASE( "O2Toxicity: CNS Toxicity" ) {
    o2toxicity.calculate(18000000, 124.142857143, air);
    CHECK( o2toxicity.getPO2() == Approx(1.0).epsilon(0.00001) );
    REQUIRE( o2toxicity.getCNSToxicity() == Approx(1.0).epsilon(0.00001) );
}