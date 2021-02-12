#include "utility.hpp"

namespace blacktip
{
	double Utility::millisToSeconds(const unsigned long millis)
	{
		return millis / 1000.0;
	}

	double Utility::millisToMinutes(const unsigned long millis)
	{
		return millis / 1000.0 / 60.0;
	}

	double Utility::minutesToHours(const double minutes)
	{
		return minutes / 60.0;
	}

	double Utility::hoursToMinutes(const double hours)
	{
		return hours * 60;
	}
}
