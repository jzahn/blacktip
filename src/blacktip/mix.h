#ifndef MIX_H
#define MIX_H

namespace blacktip
{
	class Mix
	{
	private:
		char const *name = "air";
		double percentNitrogen = 0.79;
		double percentHelium = 0.0;
		double percentOxygen = 0.21;

	public:
		Mix(){}
		Mix(char const *name, const double pN, const double pHe, const double pO);
		virtual ~Mix() {}

		char const *getName() {return name;}
		double getPercentNitrogen() const {return percentNitrogen;}
		double getPercentHelium() const {return percentHelium;}
		double getPercentOxygen() const {return percentOxygen;}
	};

}

#endif
