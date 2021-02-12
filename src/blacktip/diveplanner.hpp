#ifndef DIVEPLANNER_H
#define DIVEPLANNER_H

#include "decoalgorithim.hpp"
#include "mix.hpp"
#include "ascentmeter.hpp"

namespace blacktip
{
	class DivePlanner
	{
	protected:
		DecoAlgorithim *decoAlgorithim = nullptr;

	public:
		virtual void calculate(unsigned long millis,
				double depth) = 0;
		DecoAlgorithim* getDecoAlgorithim() {return decoAlgorithim;}
	};
}

#endif
