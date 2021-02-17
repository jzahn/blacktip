#ifndef ZHL16_H
#define ZHL16_H

#include <string>

#include "decoalgorithm.hpp"

namespace blacktip
{
	class AlgorithmZHL16 : public DecoAlgorithm
	{
	private:

		static constexpr unsigned short NUM_COMPARTMENTS = 16;

		static constexpr double COMPARTMENT1_HALFTIME = 4.0;
		static constexpr double COMPARTMENT1B_HALFTIME = 5.0;
		static constexpr double COMPARTMENT2_HALFTIME = 8.0;
		static constexpr double COMPARTMENT3_HALFTIME = 12.5;
		static constexpr double COMPARTMENT4_HALFTIME = 18.5;
		static constexpr double COMPARTMENT5_HALFTIME = 27.0;
		static constexpr double COMPARTMENT6_HALFTIME = 38.3;
		static constexpr double COMPARTMENT7_HALFTIME = 54.3;
		static constexpr double COMPARTMENT8_HALFTIME = 77.0;
		static constexpr double COMPARTMENT9_HALFTIME = 109.0;
		static constexpr double COMPARTMENT10_HALFTIME = 146.0;
		static constexpr double COMPARTMENT11_HALFTIME = 187.0;
		static constexpr double COMPARTMENT12_HALFTIME = 239.0;
		static constexpr double COMPARTMENT13_HALFTIME = 305.0;
		static constexpr double COMPARTMENT14_HALFTIME = 390.0;
		static constexpr double COMPARTMENT15_HALFTIME = 498.0;
		static constexpr double COMPARTMENT16_HALFTIME = 635.0;

		static constexpr double COMPARTMENT1_MVALUE = 106.4;
		static constexpr double COMPARTMENT1B_MVALUE = 97.3;
		static constexpr double COMPARTMENT2_MVALUE = 83.2;
		static constexpr double COMPARTMENT3_MVALUE = 73.8;
		static constexpr double COMPARTMENT4_MVALUE = 66.8;
		static constexpr double COMPARTMENT5_MVALUE = 60.8;
		static constexpr double COMPARTMENT6_MVALUE = 55.6;
		static constexpr double COMPARTMENT7_MVALUE = 52.3;
		static constexpr double COMPARTMENT8_MVALUE = 50.1;
		static constexpr double COMPARTMENT9_MVALUE = 48.5;
		static constexpr double COMPARTMENT10_MVALUE = 47.2;
		static constexpr double COMPARTMENT11_MVALUE = 46.1;
		static constexpr double COMPARTMENT12_MVALUE = 45.1;
		static constexpr double COMPARTMENT13_MVALUE = 44.1;
		static constexpr double COMPARTMENT14_MVALUE = 43.1;
		static constexpr double COMPARTMENT15_MVALUE = 42.4;
		static constexpr double COMPARTMENT16_MVALUE = 41.8;

		static constexpr double COMPARTMENT1_SLOPE = 1.9082;
		static constexpr double COMPARTMENT1B_SLOPE = 1.7928;
		static constexpr double COMPARTMENT2_SLOPE = 1.5352;
		static constexpr double COMPARTMENT3_SLOPE = 1.3847;
		static constexpr double COMPARTMENT4_SLOPE = 1.2780;
		static constexpr double COMPARTMENT5_SLOPE = 1.2306;
		static constexpr double COMPARTMENT6_SLOPE = 1.1857;
		static constexpr double COMPARTMENT7_SLOPE = 1.1504;
		static constexpr double COMPARTMENT8_SLOPE = 1.1223;
		static constexpr double COMPARTMENT9_SLOPE = 1.0999;
		static constexpr double COMPARTMENT10_SLOPE = 1.0844;
		static constexpr double COMPARTMENT11_SLOPE = 1.0731;
		static constexpr double COMPARTMENT12_SLOPE = 1.0635;
		static constexpr double COMPARTMENT13_SLOPE = 1.0552;
		static constexpr double COMPARTMENT14_SLOPE = 1.0478;
		static constexpr double COMPARTMENT15_SLOPE = 1.0414;
		static constexpr double COMPARTMENT16_SLOPE = 1.0359;

	public:
		AlgorithmZHL16();
		~AlgorithmZHL16() override;

		std::string getAlgorithmName() const override {return "zhl-16c";};
	};

}

#endif
