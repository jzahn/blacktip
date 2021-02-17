#include "ascentmeter.hpp"

#include "utility.hpp"

namespace blacktip
{

	void AscentMeter::calculate(const unsigned long millis, const double depth)
	{
		static unsigned long time_elapsed = 0;
		static double starting_depth = 0.0;

		time_elapsed += millis;

		if (time_elapsed >= delay)
		{
			// TODO bugprone-narrowing-conversions
			instantaneousRate = (starting_depth - depth) *
					Utility::secondsPerMinute / (time_elapsed / delay);
			time_elapsed = 0;
			starting_depth = depth;
		}
	}
}
