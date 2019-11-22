#include "haldane.h"

namespace blacktip 
{
	AlgorithimHaldane::AlgorithimHaldane() 
	{
		numCompartments = NUM_COMPARTMENTS;

		compartment = new Compartment[NUM_COMPARTMENTS]
		{
			Compartment(COMPARTMENT1_HALFTIME),
			Compartment(COMPARTMENT2_HALFTIME),
			Compartment(COMPARTMENT3_HALFTIME),
			Compartment(COMPARTMENT4_HALFTIME),
			Compartment(COMPARTMENT5_HALFTIME)
		};
	}

	AlgorithimHaldane::~AlgorithimHaldane()
	{
		delete [] compartment;
	}

}