#include "mix.h"

namespace blacktip
{
	Mix::Mix(char const *name, const double pN, const double pHe, const double pO)
	{
		name = name;
		fractionNitrogen = pN;
		fractionHelium = pHe;
		fractionOxygen = pO;
	}

	Mix::Mix(const Mix &mix)
	{
		// TODO Mix::name
		Mix::fractionNitrogen = mix.fractionNitrogen;
		Mix::fractionHelium = mix.fractionHelium;
		Mix::fractionOxygen = mix.fractionOxygen;
	}

	Mix Mix::getMixAir()
	{
		return {"[air]", 0.79, 0.0, 0.21};
	}

	Mix Mix::getMixEan32()
	{
		return {"ean32", 0.68, 0.0, 0.32};
	}

	Mix Mix::getMixEan36()
	{
		return {"ean36", 0.64, 0.0, 0.36};
	}

}
