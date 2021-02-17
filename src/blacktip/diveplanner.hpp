#ifndef DIVEPLANNER_H
#define DIVEPLANNER_H

#include "decoalgorithm.hpp"
#include "mix.hpp"
#include "ascentmeter.hpp"

namespace blacktip
{
	class DivePlanner
	{
	protected:
		DecoAlgorithm *decoAlgorithm = nullptr;

	public:
		virtual void calculate(unsigned long millis,
				double depth) = 0;
		DecoAlgorithm* getDecoAlgorithm() {return decoAlgorithm;}
	};
}

#endif
