#ifndef UTILITY_H
#define UTILITY_H

namespace blacktip 
{
	class Utility 
	{
	public:
		static double millisToMinutes(const unsigned long millis);
		static double minutesToHours(const double minutes);
		static double hoursToMinutes(const double hours);
	};
}

#endif