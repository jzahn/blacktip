#ifndef COMPARTMENT_H
#define COMPARTMENT_H

namespace blacktip
{
	class Compartment
	{
	private:
		double halfTime = 0.0;
		double mValue = 0.0;
		double slope = 0.0;

		double pressureNitrogen = 26.070;
		double minutesRemaining = 0.0;
		double depthCeiling = 0.0;
		double depthFloor = 0.0;

		double percentMValue = 0.0;

		bool isMaxed = false;
		bool isAbleToMax = false;
		bool isOffgassing = false;
		bool isDecompressing = false;
		bool modelViolated = false;

	public:
		Compartment(const double halfTime);
		Compartment(const double halfTime, const double mValue);
		Compartment(const double halfTime, const double mValue, const double slope);
		virtual ~Compartment() {};

		void calculate(const unsigned long millis, const double depth);
		double getMinutesRemaining() const {return minutesRemaining;};
		double getHalfTime() const {return halfTime;}
		double getMValue() const {return mValue;}
		double getPressureNitrogen() const {return pressureNitrogen;}
		double getCeiling() const {return depthCeiling;}
		double getFloor() const {return depthFloor;}
		double getPercentMValue() const {return percentMValue;}

		bool getIsMaxed() const {return isMaxed;}
		bool getIsAbleToMax() const {return isAbleToMax;}
		bool getIsOffgassing() const {return isOffgassing;}
		bool getIsDecompressing() const {return isDecompressing;}
		bool getModelViolated() const {return modelViolated;}
	};
}

#endif
