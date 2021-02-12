#ifndef COMPARTMENT_H
#define COMPARTMENT_H

#include "mix.h"

namespace blacktip
{
	class Compartment
	{
	private:
		double halfTime = 0.0;
		double mValue = 0.0;
		double slope = 0.0;

		double pressureNitrogen = 26.070;
		double pressureHelium = 0.0;
		double minutesRemaining = 9999.9;
		double depthCeiling = 0.0; // decompressionCeiling
		double depthFloor = 0.0; // decompressionFloor

		double percentMValue = 0.0;

		bool isMaxed = false;
		bool isAbleToMax = false;
		bool isOffgassing = false;
		bool isDecompressing = false;
		bool isModelViolated = false;

	public:
		explicit Compartment(double halfTime);
		Compartment(double halfTime, double mValue);
		Compartment(double halfTime, double mValue,
				double slope);
		virtual ~Compartment() = default;

		void calculate(unsigned long millis, double depth,
				const Mix &mix);
		double getMinutesRemaining() const {return minutesRemaining;};
		double getHalfTime() const {return halfTime;}
		double getMValue() const {return mValue;}
		double getPressureNitrogen() const {return pressureNitrogen;}
		double getPressureHelium() const {return pressureHelium;}
		double getCeiling() const {return depthCeiling;}
		double getFloor() const {return depthFloor;}
		double getPercentMValue() const {return percentMValue;}

		bool getIsMaxed() const {return isMaxed;}
		bool getIsAbleToMax() const {return isAbleToMax;}
		bool getIsOffgassing() const {return isOffgassing;}
		bool getIsDecompressing() const {return isDecompressing;}
		bool getIsModelViolated() const {return isModelViolated;}
	};
}

#endif
