#ifndef ASCENTMETER_H
#define ASCENTMETER_H

namespace blacktip 
{
	class AscentMeter
	{
	private:
		static constexpr int delay = 1000;
		double instantaneousRate = 0.0;
	public:
		void calculate(const unsigned long millis, const double depth);

		double getInstantaneousRate() {return instantaneousRate;}
	};
}

#endif