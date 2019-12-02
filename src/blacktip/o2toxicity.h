#ifndef O2TOXICITY_H
#define O2TOXICITY_H

#include "mix.h"

namespace blacktip
{
    class O2ToxicityMeter
    {
    private:
        double pO2 = 0.0;
        double oxygenCentralNervous = 0.0; // unit OTU
        double oxygenPulmonary = 0.0; // unit OTU

        double getCNSSlope(const double pO2) const;
        double getCNSIntercept(const double pO2) const;

    public:
        void calculate(const unsigned long millis, const double depth,
				const Mix &mix);
    };
}

#endif
