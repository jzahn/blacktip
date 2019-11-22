#ifndef DIVEPLANNER_H
#define DIVEPLANNER_H

#include "decoalgorithim.h"
#include "mix.h"
#include "ascentmeter.h"

namespace blacktip
{
	class DivePlanner
	{
	protected:
		DecoAlgorithim *decoAlgorithim;

	public:
		virtual void calculate(const unsigned long millis, const double depth) = 0;
		DecoAlgorithim* getDecoAlgorithim() {return decoAlgorithim;}
	};
}

#endif