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
		virtual ~DecoAlgorithim() = default;

		virtual std::string getAlgorithimName() const = 0;
		void calculate(unsigned long millis, double depth,
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
			return compartments[compartmentNumber];
		};

	protected:
		unsigned short numCompartments = 0;
		Compartment *compartments = nullptr;
	};
}

#endif
