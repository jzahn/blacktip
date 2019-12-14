#include "decoalgorithim.h"

namespace blacktip
{
	void DecoAlgorithim::calculate(const unsigned long millis,
			const double depth, const Mix &mix)
	{
		double minutesRemaining = 9999.9;
		double ceiling = 0.0;
		double floor = 0.0;
		double saturation = 0.0;

		isModelViolated = false;

		for (int i = 0; i < numCompartments; i++)
		{
			// calculate compartment pressure
			compartments[i].calculate(millis, depth, mix);

			// calculate minutes remaining
			double cptMinsRemaining = compartments[i].getMinutesRemaining();

			if (compartments[i].getIsMaxed())
			{
				minutesRemaining = 0.0;
			}
			else if (cptMinsRemaining < minutesRemaining &&
					!compartments[i].getIsOffgassing() &&
					compartments[i].getIsAbleToMax())
			{
				minutesRemaining = cptMinsRemaining;
				if (minutesRemaining < 0.0)
				{
					minutesRemaining = 0.0;
				}
			}

			// calculate ceiling
			if (compartments[i].getCeiling() > ceiling &&
					compartments[i].getIsMaxed())
			{
				ceiling = compartments[i].getCeiling();
			}

			// calculate floor
			if (compartments[i].getFloor() > floor)
			{
				floor = compartments[i].getFloor();
			}

			//calculate saturation
			if (compartments[i].getPercentMValue() > saturation)
			{
				saturation = compartments[i].getPercentMValue();
			}

			// check for model violation
			if (compartments[i].getIsModelViolated())
			{
				isModelViolated = true;
			}
		}

		DecoAlgorithim::minutesRemaining = minutesRemaining;
		DecoAlgorithim::ceiling = ceiling;
		DecoAlgorithim::floor = floor;
		DecoAlgorithim::saturation = saturation;
	}
}
