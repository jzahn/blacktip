#ifndef DSAT_H
#define DSAT_H

#include <string>

#include "decoalgorithim.h"

namespace blacktip 
{
	class AlgorithimDSAT : public DecoAlgorithim
	{
	private:

		static constexpr unsigned short NUM_COMPARTMENTS = 14;

		static constexpr double COMPARTMENT_5MIN_HALFTIME = 5.0;
		static constexpr double COMPARTMENT_10MIN_HALFTIME = 10.0;
		static constexpr double COMPARTMENT_20MIN_HALFTIME = 20.0;
		static constexpr double COMPARTMENT_30MIN_HALFTIME = 30.0;
		static constexpr double COMPARTMENT_40MIN_HALFTIME = 40.0;
		static constexpr double COMPARTMENT_60MIN_HALFTIME = 60.0;
		static constexpr double COMPARTMENT_80MIN_HALFTIME = 80.0;
		static constexpr double COMPARTMENT_100MIN_HALFTIME = 100.0;
		static constexpr double COMPARTMENT_120MIN_HALFTIME = 120.0;
		static constexpr double COMPARTMENT_160MIN_HALFTIME = 160.0;
		static constexpr double COMPARTMENT_200MIN_HALFTIME = 200.0;
		static constexpr double COMPARTMENT_240MIN_HALFTIME = 240.0;
		static constexpr double COMPARTMENT_360MIN_HALFTIME = 360.0;
		static constexpr double COMPARTMENT_480MIN_HALFTIME = 480.0;

		static constexpr double COMPARTMENT_5MIN_MVALUE = 99.08;
		static constexpr double COMPARTMENT_10MIN_MVALUE = 82.63;
		static constexpr double COMPARTMENT_20MIN_MVALUE = 66.89;
		static constexpr double COMPARTMENT_30MIN_MVALUE = 59.74;
		static constexpr double COMPARTMENT_40MIN_MVALUE = 55.73;
		static constexpr double COMPARTMENT_60MIN_MVALUE = 51.44;
		static constexpr double COMPARTMENT_80MIN_MVALUE = 49.21;
		static constexpr double COMPARTMENT_100MIN_MVALUE = 47.85;
		static constexpr double COMPARTMENT_120MIN_MVALUE = 46.93;
		static constexpr double COMPARTMENT_160MIN_MVALUE = 45.78;
		static constexpr double COMPARTMENT_200MIN_MVALUE = 45.07;
		static constexpr double COMPARTMENT_240MIN_MVALUE = 44.60;
		static constexpr double COMPARTMENT_360MIN_MVALUE = 43.81;
		static constexpr double COMPARTMENT_480MIN_MVALUE = 43.40;

		static constexpr short COMPARTMENT_60MIN = 5;
		static constexpr double SURFACE_PN2 = 26.070;
		static constexpr int NUM_PRESSURE_GROUPS = 26;

	public:
		AlgorithimDSAT();
		~AlgorithimDSAT() override;

		std::string getAlgorithimName() const override {return "dsat-rdp";};
		char getPressureGroup() const;
	};

}

#endif