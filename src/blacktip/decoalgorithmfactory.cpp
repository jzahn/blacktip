#include "decoalgorithmfactory.hpp"

#include <cstring>

#include "haldane.hpp"
#include "workman.hpp"
#include "dsat.hpp"
#include "zhl16.hpp"

namespace blacktip
{
	DecoAlgorithm *DecoAlgorithmFactory::getAlgorithm(char const *algorithmName)
	{
		if (strcmp(algorithmName, "haldane") == 0)
			return new AlgorithmHaldane();
		else if (strcmp(algorithmName, "workman") == 0)
			return new AlgorithmWorkman();
		else if (strcmp(algorithmName, "dsat") == 0)
			return new AlgorithmDSAT();
		else if (strcmp(algorithmName, "zhl16") == 0)
			return new AlgorithmZHL16();
		else
			return new AlgorithmDSAT();
	}
}
