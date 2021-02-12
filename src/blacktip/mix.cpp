#include "mix.hpp"

#include <cstring>

namespace blacktip
{
	Mix::Mix(char *name, const double pN, const double pHe, const double pO)
	{
		Mix::name = name;
		Mix::fractionNitrogen = pN;
		Mix::fractionHelium = pHe;
		Mix::fractionOxygen = pO;
	}

	Mix Mix::getMixAir()
	{
		return {(char*)"air", 0.79, 0.0, 0.21};
	}

	Mix Mix::getMixEan32()
	{
		return {(char*)"ean32", 0.68, 0.0, 0.32};
	}

	Mix Mix::getMixEan36()
	{
		return {(char*)"ean36", 0.64, 0.0, 0.36};
	}
}
