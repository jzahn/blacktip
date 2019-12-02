#include "o2toxicity.h"

#include "utility.h"

namespace blacktip
{
    void O2ToxicityMeter::calculate(const unsigned long millis,
            const double depth, const Mix &mix)
    {
        // calculate pO2
        double atm = (33 + depth) / 33;
        pO2 = mix.getFractionOxygen() * atm;

        // only accumulate o2 tox at pp > 0.5
        if (pO2 <= 0.5)
            return;

        // accumulate CNS toxicity

        // accumulate Pulmonary toxicity
    }

    double O2ToxicityMeter::getCNSSlope(const double pO2) const
    {
        return 0.0;
    }

    double O2ToxicityMeter::getCNSIntercept(const double pO2) const
    {
        return 0.0;
    }
}
