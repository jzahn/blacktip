#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "src/compartment.h"
#include "src/dsat.h"
#include "src/mix.h"
#include "src/o2toxicity.h"

using namespace blacktip;

Mix air = Mix::getMixAir();
Mix ean32 = Mix::getMixEan32();
Mix ean36 = Mix::getMixEan36();

// Compartment Tests
static constexpr double COMPARTMENT_60MIN_DSAT_HALFTIME = 60.0;
static constexpr double COMPARTMENT_60MIN_DSAT_MVALUE = 51.44;
Compartment compartment = {COMPARTMENT_60MIN_DSAT_HALFTIME,
        COMPARTMENT_60MIN_DSAT_MVALUE};

TEST_CASE( "Compartment: 0 State" ) {
    REQUIRE( compartment.getPressureNitrogen() == 26.070 );
    REQUIRE( compartment.getMinutesRemaining() == 9999.9 );
    REQUIRE( compartment.getIsMaxed() == false );
    REQUIRE( compartment.getPercentMValue() == 0.0 );
}

// DecoAlgorithim Tests
AlgorithimDSAT algorithimDSAT;

TEST_CASE( "AlgorithimDSAT: 0 State" ) {
    REQUIRE( algorithimDSAT.getMinutesRemaining() == 0.0 );
    //REQUIRE( algorithimDSAT.getCeiling() == 0.0 ); // TODO Link error???
    REQUIRE( algorithimDSAT.getFloor() == 0.0 );
    REQUIRE( algorithimDSAT.getSaturation() == 0.0 );
    REQUIRE( algorithimDSAT.getIsModelViolated() == false );
}

// O2 Toxicity Tests
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

TEST_CASE( "O2Toxicity: Reset" ) {
    o2toxicity.reset();
    REQUIRE( o2toxicity.getPO2() == 0.0 );
    REQUIRE( o2toxicity.getCNSToxicity() == 0.0 );
    REQUIRE( o2toxicity.getPulmonaryToxicity() == 0.0 );
}
