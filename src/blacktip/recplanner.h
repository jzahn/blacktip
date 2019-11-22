#ifndef RECPLANNER_H
#define RECPLANNER_H

#include "diveplanner.h"

namespace blacktip 
{
	enum DiveMode {SURF, DIVE, DECO, SSTP, DSTP, BSTP};	

	class RecreationalPlanner : public DivePlanner
	{
	private:
		double depth = 0.0;
		Mix mix;
		AscentMeter ascentMeter;

		bool requiredSafetyStop = false;
		bool requiredDecompressionStop = false;
		double repetitiveDiveMinutes = 0.0;
		double noFlyMinutes = 0.0;
		double noDiveMinutes = 0.0;
		int diveNumber = 0;
		bool diveInProgress = false;
		int gradientFactor = 100;

		void setFlags(const unsigned long millis, const double depth);
		void resetFlags();
		void decrementTimers(const unsigned long millis);

	public:
		RecreationalPlanner(char const *algorithimName);
		virtual ~RecreationalPlanner();

		void calculate(const unsigned long millis, const double depth);
		void setMix(Mix mix) {RecreationalPlanner::mix = mix;}
		void setGradientFactor(int gradientFactor) {RecreationalPlanner::gradientFactor = gradientFactor;}
		AscentMeter &getAscentMeter() {return ascentMeter;}
		int getDiveNumber() const {return diveNumber;}
		bool getSafetyStopRequired() const {return requiredSafetyStop;}
		bool getDecompressionStopRequired() const {return requiredDecompressionStop;}
		bool getDiveInProgress() const {return diveInProgress;}
		double getRepetitiveDiveMinutes() const {return repetitiveDiveMinutes;}
		double getNoFlyMinutes() const {return noFlyMinutes;}
		double getNoDiveMinutes() const {return noDiveMinutes;}
	};
}

#endif