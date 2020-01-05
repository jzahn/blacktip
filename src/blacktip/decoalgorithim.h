#ifndef DECOALGORITHIM_H
#define DECOALGORITHIM_H

#include <string>

#include "compartment.h"
#include "mix.h"

namespace blacktip
{
	class DecoAlgorithim
	{
	private:
		double minutesRemaining = 0.0;
		double ceiling = 0.0;
		double floor = 0.0;
		double saturation = 0.0;
		bool isModelViolated = false;

	public:
		virtual ~DecoAlgorithim() {};

		virtual std::string getAlgorithimName() const = 0;
		void calculate(const unsigned long millis, const double depth,
				const Mix &mix);
		double getMinutesRemaining() const {return minutesRemaining;};
		double getCeiling() const {return ceiling;};
		double getFloor() const {return floor;};
		double getSaturation() const {return saturation;};
		bool getIsModelViolated() const {return isModelViolated;};

		unsigned short getNumberOfCompartments() const
		{
			return numCompartments;
		};

		Compartment getCompartment(const unsigned short compartmentNumber) const
		{
			// TODO unit test to figure out what 0 does in this context
			return compartmentNumber < numCompartments ? 
					compartments[compartmentNumber] : 0; 
		};

	protected:
		unsigned short numCompartments = 0;
		Compartment *compartments = 0;
	};
}

#endif
