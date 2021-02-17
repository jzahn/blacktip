#ifndef HALDANE_H
#define HALDANE_H

#include <string>

#include "decoalgorithm.hpp"

namespace blacktip
{
	class AlgorithmHaldane : public DecoAlgorithm
	{
	private:
		static constexpr unsigned short NUM_COMPARTMENTS = 5;

		static constexpr double COMPARTMENT1_HALFTIME = 5.0;
		static constexpr double COMPARTMENT2_HALFTIME = 10.0;
		static constexpr double COMPARTMENT3_HALFTIME = 20.0;
		static constexpr double COMPARTMENT4_HALFTIME = 40.0;
		static constexpr double COMPARTMENT5_HALFTIME = 75.0;

	public:
		AlgorithmHaldane();
		~AlgorithmHaldane() override;

		std::string getAlgorithmName() const override {return "haldane";};
	};

}

#endif
