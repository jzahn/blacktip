#include "decoalgorithimfactory.hpp"

#include <cstring>

#include "haldane.hpp"
#include "workman.hpp"
#include "dsat.hpp"
#include "zhl16.hpp"

namespace blacktip
{
	DecoAlgorithim *DecoAlgorithimFactory::getAlgorithim(char const *algorithimName)
	{
		if (strcmp(algorithimName, "haldane") == 0)
			return new AlgorithimHaldane();
		else if (strcmp(algorithimName, "workman") == 0)
			return new AlgorithimWorkman();
		else if (strcmp(algorithimName, "dsat") == 0)
			return new AlgorithimDSAT();
		else if (strcmp(algorithimName, "zhl16") == 0)
			return new AlgorithimZHL16();
		else
			return new AlgorithimDSAT();
	}
}
