#include "decoalgorithim.h"

namespace blacktip 
{
	void DecoAlgorithim::calculate(const unsigned long millis, const double depth)
	{
		double minutesRemaining = 9999.0;
		double ceiling = 0.0;
		double floor = 0.0;
		double saturation = 0.0;

		modelViolated = false;

		for (int i = 0; i < numCompartments; i++)
		{
			// calculate compartment pressure
			compartment[i].calculate(millis, depth);

			// calculate minutes remaining
			double cptMinsRemaining = compartment[i].getMinutesRemaining();

			if (compartment[i].getIsMaxed())
				minutesRemaining = 0.0;
			else if (cptMinsRemaining < minutesRemaining && 
					 !compartment[i].getIsOffgassing() && 
					 compartment[i].getIsAbleToMax())
			{
				minutesRemaining = cptMinsRemaining;
				if (minutesRemaining < 0.0)
					minutesRemaining = 0.0;
			}

			// calculate ceiling
			if (compartment[i].getCeiling() > ceiling && compartment[i].getIsMaxed())
				ceiling = compartment[i].getCeiling();

			// calculate floor
			if (compartment[i].getFloor() > floor)
				floor = compartment[i].getFloor();

			//calculate saturation
			if (compartment[i].getPercentMValue() > saturation)
				saturation = compartment[i].getPercentMValue();

			// check for model violation
			if (compartment[i].getModelViolated())
				modelViolated = true;
		}

		DecoAlgorithim::minutesRemaining = minutesRemaining;
		DecoAlgorithim::ceiling = ceiling;
		DecoAlgorithim::floor = floor;
		DecoAlgorithim::saturation = saturation;
	}
}