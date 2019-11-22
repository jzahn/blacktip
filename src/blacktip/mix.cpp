#include "mix.h"

namespace blacktip 
{
	Mix::Mix(char const *name, const double pN, const double pHe, const double pO)
	{
		name = name;
		percentNitrogen = pN;
		percentHelium = pHe;
		percentOxygen = pO;
	}

}