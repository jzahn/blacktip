#ifndef MIX_H
#define MIX_H

namespace blacktip
{
	class Mix
	{
	private:
		char *name = (char*)"air";
		double fractionNitrogen = 0.79;
		double fractionHelium = 0.0;
		double fractionOxygen = 0.21;

	public:
		Mix() = default;
		Mix(char *name, double pN, double pHe, double pO);
		virtual ~Mix() = default;

		char const *getName() {return name;}
		double getFractionNitrogen() const {return fractionNitrogen;}
		double getFractionHelium() const {return fractionHelium;}
		double getFractionOxygen() const {return fractionOxygen;}

		static Mix getMixAir();
		static Mix getMixEan32();
		static Mix getMixEan36();
	};
}

#endif
