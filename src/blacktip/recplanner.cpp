#include "recplanner.hpp"

#include "utility.hpp"
#include "decoalgorithmfactory.hpp"

namespace blacktip
{
	RecreationalPlanner::RecreationalPlanner(char const *algorithmName)
	{
        decoAlgorithm = DecoAlgorithmFactory::getAlgorithm(algorithmName);
	}

	RecreationalPlanner::~RecreationalPlanner()
	{
		delete decoAlgorithm;
	}

	void RecreationalPlanner::calculate(const unsigned long millis,
			const double depth)
	{
		RecreationalPlanner::depth = depth;
		decoAlgorithm->calculate(millis, depth, mix);
		ascentMeter.calculate(millis, depth);
		o2toxicity.calculate(millis, depth, mix);
		setState(millis, depth);
	}

	void RecreationalPlanner::setMix(const Mix mix)
	{
		if (depth == 0.0)
		{
			RecreationalPlanner::mix = mix;
		}
	}

	void RecreationalPlanner::setState(const unsigned long millis,
			const double depth)
	{
		if (depth > 0.0 && !diveInProgress)
		{
			startDive();
		}
		else if (depth == 0.0 && diveInProgress)
		{
			endDive();
		}

		if (depth == 0.0)
		{
			decrementSurfaceTimers(millis);
		}

		decrementTimers(millis);
		checkSafetyStopRequired(depth);
		checkDecompressionStopRequired(depth);
		checkModelViolation(depth);
	}

	void RecreationalPlanner::startDive()
	{
		diveInProgress = true;
		diveNumber++;
	}

	void RecreationalPlanner::endDive()
	{
		repetitiveDiveMinutes = REPETIVE_DIVE_MINS;

		if (diveNumber > 1)
		{
			noFlyMinutes = MULTI_DIVE_NO_FLY_MINS;
		}
		else
		{
			noFlyMinutes = SINGLE_DIVE_NO_FLY_MINS;
		}

		diveInProgress = false;
		requiredSafetyStop = false;
		requiredDecompressionStop = false;
	}

	void RecreationalPlanner::checkSafetyStopRequired(const double depth)
	{
		if (diveInProgress && depth >= MAX_NO_SAFETY_STOP_DEPTH &&
				!requiredSafetyStop)
		{
			requiredSafetyStop = true;
		}
		else if (diveInProgress && (decoAlgorithm->getSaturation() * 100.0) >
                                   MAX_SAFETY_STOP_M_THRESHOLD && !requiredSafetyStop)
		{
			requiredSafetyStop = true;
		}
	}

	void RecreationalPlanner::checkDecompressionStopRequired(const double depth)
	{
		if (diveInProgress && decoAlgorithm->getCeiling() > 0.0 &&
            !requiredDecompressionStop)
		{
			requiredDecompressionStop = true;
			requiredSafetyStop = true;
		}
		
		if (decoAlgorithm->getCeiling() == 0.0 && requiredDecompressionStop)
		{
			requiredDecompressionStop = false;
		}
	}

	void RecreationalPlanner::checkModelViolation(const double depth)
	{
		if (decoAlgorithm->getIsModelViolated())
		{
			noDiveMinutes = MODEL_VIOLATION_NODIVE_MINUTES;
		}
	}

	void RecreationalPlanner::decrementSurfaceTimers(const unsigned long millis)
	{
		// repetitive dive hours
		if (repetitiveDiveMinutes > 0.0)
		{
			repetitiveDiveMinutes -= Utility::millisToMinutes(millis);
		}
		else if (repetitiveDiveMinutes < 0.0)
		{
			repetitiveDiveMinutes = 0.0;
			diveNumber = 0;
		}

		// no fly hours
		if (noFlyMinutes > 0.0)
		{
			noFlyMinutes -= Utility::millisToMinutes(millis);
		}
		else if (noFlyMinutes < 0.0)
		{
			noFlyMinutes = 0.0;
		}

		// no dive hours
		if (noDiveMinutes > 0.0)
		{
			noDiveMinutes -= Utility::millisToMinutes(millis);
		}
		else if (noDiveMinutes < 0.0)
		{
			noDiveMinutes = 0.0;
		}
	}

	void RecreationalPlanner::decrementTimers(const unsigned long millis)
	{
		// o2 toxicity timer
		if (o2ToxicityResetMinutes > 0.0)
		{
			o2ToxicityResetMinutes -= Utility::millisToMinutes(millis);
		}
		else if (o2ToxicityResetMinutes < 0.0)
		{
			o2toxicity.reset();
			o2ToxicityResetMinutes = O2_TOXICITY_RESET_MINUTES - o2ToxicityResetMinutes;
		}
	}
}
