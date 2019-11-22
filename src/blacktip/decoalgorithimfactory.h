#ifndef DECOALGORITHIMFACTORY_H
#define DECOALGORITHIMFACTORY_H

#include "decoalgorithim.h"

namespace blacktip 
{
	class DecoAlgorithimFactory 
	{
	public:
		static DecoAlgorithim *getAlgorithim(char const *algorithimName);
	};
}

#endif