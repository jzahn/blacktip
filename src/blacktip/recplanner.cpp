#include "recplanner.h"

#include <cstring>

#include "haldane.h"
#include "workman.h"
#include "dsat.h"
#include "zhl16.h"
#include "utility.h"
#include "decoalgorithimfactory.h"

namespace blacktip
{
	RecreationalPlanner::RecreationalPlanner(char const *algorithimName)
	{
		decoAlgorithim = DecoAlgorithimFactory::getAlgorithim(algorithimName);
	}

	RecreationalPlanner::~RecreationalPlanner()
	{
		delete decoAlgorithim;
	}

	void RecreationalPlanner::calculate(const unsigned long millis, const double depth)
	{
		RecreationalPlanner::depth = depth;
		decoAlgorithim->calculate(millis, depth);
		ascentMeter.calculate(millis, depth);

		setFlags(millis, depth);
	}

	void RecreationalPlanner::setFlags(const unsigned long millis, const double depth)
	{
		// dive in progress
		if (depth > 0.0 && !diveInProgress)
		{
			diveInProgress = true;
			diveNumber++;
		}
		else if (depth == 0.0 && diveInProgress)
		{
			repetitiveDiveMinutes = REPETIVE_DIVE_MINS;

			if (diveNumber > 1)
				noFlyMinutes = MULTI_DIVE_NO_FLY_MINS;
			else
				noFlyMinutes = SINGLE_DIVE_NO_FLY_MINS;

			diveInProgress = false;
			resetFlags();
		}
		else if (depth == 0.0 && !diveInProgress)
		{
			decrementTimers(millis);
		}

		// required safety stop
		if (diveInProgress && depth >= MAX_NO_SAFETY_STOP_DEPTH && !requiredSafetyStop)
			requiredSafetyStop = true;
		else if (diveInProgress && (decoAlgorithim->getSaturation() * 100.0) > 85.0 && !requiredSafetyStop)
			requiredSafetyStop = true;

		// required decompression stop
		if (diveInProgress && decoAlgorithim->getCeiling() > 0.0 && !requiredDecompressionStop)
		{
			requiredDecompressionStop = true;
			requiredSafetyStop = true;
		}
		if (decoAlgorithim->getCeiling() == 0.0 && requiredDecompressionStop)
			requiredDecompressionStop = false;

		// model violation
		if (decoAlgorithim->getModelViolated())
			noDiveMinutes = Utility::hoursToMinutes(24);
	}

	void RecreationalPlanner::resetFlags()
	{
		requiredSafetyStop = false;
		requiredDecompressionStop = false;
	}

	void RecreationalPlanner::decrementTimers(const unsigned long millis)
	{
		if (repetitiveDiveMinutes > 0.0)
		{
			repetitiveDiveMinutes -= Utility::millisToMinutes(millis);
		}
		else
		{
			repetitiveDiveMinutes = 0.0;
			diveNumber = 0;
		}

		// no fly hours
		if (noFlyMinutes > 0.0)
		{
			noFlyMinutes -= Utility::millisToMinutes(millis);
		}
		else
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
}
