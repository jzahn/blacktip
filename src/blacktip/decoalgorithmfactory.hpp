#ifndef DECOALGORITHMFACTORY_H
#define DECOALGORITHMFACTORY_H

#include "decoalgorithm.hpp"

namespace blacktip
{
	class DecoAlgorithmFactory
	{
	public:
		static DecoAlgorithm *getAlgorithm(char const *algorithmName);
	};
}

#endif
