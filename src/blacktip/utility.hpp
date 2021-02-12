#ifndef UTILITY_H
#define UTILITY_H

namespace blacktip 
{
	class Utility 
	{
	public:
		static constexpr double secondsPerMinute = 60.0;

		static double millisToSeconds(unsigned long millis);
		static double millisToMinutes(unsigned long millis);
		static double minutesToHours(double minutes);
		static double hoursToMinutes(double hours);
	};
}

#endif