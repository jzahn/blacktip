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
		void calculate(unsigned long millis, double depth);

		double getInstantaneousRate() const {return instantaneousRate;}
	};
}

#endif
