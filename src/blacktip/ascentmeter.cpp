#include "ascentmeter.h"

namespace blacktip
{

	void AscentMeter::calculate(const unsigned long millis, const double depth)
	{
		static unsigned long time_elapsed = 0;
		static double starting_depth = 0.0;

		time_elapsed += millis;

		if (time_elapsed > 1000)
		{
			instantaneousRate = (starting_depth - depth) * 60.0;
			time_elapsed = 0;
			starting_depth = depth;
		}
	}
}
