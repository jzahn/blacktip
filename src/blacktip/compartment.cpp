#include "compartment.hpp"

#include <cmath>

#include "utility.hpp"

namespace blacktip
{
	Compartment::Compartment(const double halfTime) {
		Compartment::halfTime = halfTime;
	}

	Compartment::Compartment(const double halfTime, const double mValue) {
		Compartment::halfTime = halfTime;
		Compartment::mValue = mValue;
	}

	Compartment::Compartment(const double halfTime, const double mValue,
				const double slope) {
		Compartment::halfTime = halfTime;
		Compartment::mValue = mValue;
		Compartment::slope = slope;
	}

	/* Exponential Tissue Saturation Equation (Workman form, 1954)

	D = Depth

	A = Absolute Depth (fsw)
	Depth + 33 (or less at altidude)

	Q = Final Tissue Pressure (fsw)
	Partial pressure of inert gas in the tissue
	at the end of a time interval.

	P = Initial Tissue Pressure (fsw)
	T = Time Interval
	H = Tissue Half Time

	N = Inert Gas Partial Pressure (fsw)
	Sum of the partial pressures of all gases in
	the breathing mix other than oxygen. Derived
	by multiplying absolute depth by the inert gas
	percentage decimal.

	Q = P + (1.0 - (0.5 ^(T/H))) * (N - P)

	*/

	void Compartment::calculate(const unsigned long millis, const double depth,
			const Mix &mix)
	{
		// calculate constants
		const double T = Utility::millisToMinutes(millis);
		const double A = depth + 33.0;

		const double N = A * mix.getFractionNitrogen();
		const double U = T / halfTime;
		const double P = pressureNitrogen;

		// TODO use previous depth to create Shreiner equation branch

		// calculate pressure
		pressureNitrogen = P + (1.0 - pow(0.5, U)) * (N - P);

		percentMValue = (pressureNitrogen - (33.0 * mix.getFractionNitrogen()))
				/ (mValue - (33.0 * mix.getFractionNitrogen()));

		// calculate no deco time
		double timeRemaining = 0.0;
		if (pressureNitrogen < mValue)
		{
			timeRemaining = log(1.0 - ((mValue - pressureNitrogen) /
					(N - pressureNitrogen))) * (halfTime / log(0.5));
		}

		if (timeRemaining >= 0.0)
			minutesRemaining = ceil(timeRemaining);
		else
			minutesRemaining = floor(timeRemaining);

		isAbleToMax = N >= mValue;

		isMaxed = pressureNitrogen >= mValue;

		isOffgassing = N < pressureNitrogen;

		isDecompressing = isMaxed && isOffgassing;

		if (isMaxed && slope > 0.0)
			depthCeiling = (pressureNitrogen - mValue) / slope;
		else if (isMaxed)
			depthCeiling = pressureNitrogen - mValue;

		depthFloor = pressureNitrogen / mix.getFractionNitrogen() - 33.0;

		isModelViolated = depth < depthCeiling - 0.1;

		previousDepth = depth;
	}
}
