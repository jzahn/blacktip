#include "haldane.hpp"

namespace blacktip
{
	AlgorithmHaldane::AlgorithmHaldane()
	{
		numCompartments = NUM_COMPARTMENTS;

		compartments = new Compartment[NUM_COMPARTMENTS]
		{
			Compartment(COMPARTMENT1_HALFTIME),
			Compartment(COMPARTMENT2_HALFTIME),
			Compartment(COMPARTMENT3_HALFTIME),
			Compartment(COMPARTMENT4_HALFTIME),
			Compartment(COMPARTMENT5_HALFTIME)
		};
	}

	AlgorithmHaldane::~AlgorithmHaldane()
	{
		delete [] compartments;
	}

}
