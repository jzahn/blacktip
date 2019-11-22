#ifndef WORKMAN_H
#define WORKMAN_H

#include <string>

#include "decoalgorithim.h"

namespace blacktip 
{
	class AlgorithimWorkman : public DecoAlgorithim
	{
	private:
		static constexpr unsigned short NUM_COMPARTMENTS = 9;

		static constexpr double COMPARTMENT_5MIN_HALFTIME = 5.0;
		static constexpr double COMPARTMENT_10MIN_HALFTIME = 10.0;
		static constexpr double COMPARTMENT_20MIN_HALFTIME = 20.0;
		static constexpr double COMPARTMENT_40MIN_HALFTIME = 40.0;
		static constexpr double COMPARTMENT_80MIN_HALFTIME = 80.0;
		static constexpr double COMPARTMENT_120MIN_HALFTIME = 120.0;
		static constexpr double COMPARTMENT_160MIN_HALFTIME = 160.0;
		static constexpr double COMPARTMENT_200MIN_HALFTIME = 200.0;
		static constexpr double COMPARTMENT_240MIN_HALFTIME = 240.0;

		static constexpr double COMPARTMENT_5MIN_MVALUE = 104.0;
		static constexpr double COMPARTMENT_10MIN_MVALUE = 88.0;
		static constexpr double COMPARTMENT_20MIN_MVALUE = 72.0;
		static constexpr double COMPARTMENT_40MIN_MVALUE = 56.0;
		static constexpr double COMPARTMENT_80MIN_MVALUE = 54.0;
		static constexpr double COMPARTMENT_120MIN_MVALUE = 52.0;
		static constexpr double COMPARTMENT_160MIN_MVALUE = 51.0;
		static constexpr double COMPARTMENT_200MIN_MVALUE = 51.0;
		static constexpr double COMPARTMENT_240MIN_MVALUE = 50.0;

		static constexpr double COMPARTMENT_5MIN_SLOPE = 1.8;
		static constexpr double COMPARTMENT_10MIN_SLOPE = 1.6;
		static constexpr double COMPARTMENT_20MIN_SLOPE = 1.5;
		static constexpr double COMPARTMENT_40MIN_SLOPE = 1.4;
		static constexpr double COMPARTMENT_80MIN_SLOPE = 1.3;
		static constexpr double COMPARTMENT_120MIN_SLOPE = 1.2;
		static constexpr double COMPARTMENT_160MIN_SLOPE = 1.15;
		static constexpr double COMPARTMENT_200MIN_SLOPE = 1.1;
		static constexpr double COMPARTMENT_240MIN_SLOPE = 1.1;

	public:
		AlgorithimWorkman();
		virtual ~AlgorithimWorkman();

		virtual std::string getAlgorithimName() const {return "workman";};
	};
}

#endif