#ifndef UTILITY_H
#define UTILITY_H

namespace blacktip 
{
	class Utility 
	{
	public:
		static constexpr double secondsPerMinute = 60.0;

		static double millisToSeconds(const unsigned long millis);
		static double millisToMinutes(const unsigned long millis);
		static double minutesToHours(const double minutes);
		static double hoursToMinutes(const double hours);
	};
}

#endif