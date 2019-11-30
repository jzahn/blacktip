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
		double minutesRemaining;
		double ceiling;
		double floor;
		double saturation;
		bool modelViolated;

	public:
		virtual ~DecoAlgorithim() {};

		virtual std::string getAlgorithimName() const = 0;
		void calculate(const unsigned long millis, const double depth, const Mix &mix);
		double getMinutesRemaining() const {return minutesRemaining;};
		double getCeiling() const {return ceiling;};
		double getFloor() const {return floor;};
		double getSaturation() const {return saturation;};
		bool getModelViolated() const {return modelViolated;};

		unsigned short getNumberOfCompartments() const
		{
			return numCompartments;
		};

		Compartment getCompartment(const unsigned short compartmentNumber) const
		{
			return compartment[compartmentNumber];
		};

	protected:
		unsigned short numCompartments = 0;
		Compartment *compartment = 0;
	};
}

#endif
