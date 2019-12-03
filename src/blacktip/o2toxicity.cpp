#include "o2toxicity.h"

#include "utility.h"

namespace blacktip
{
    void O2Toxicity::calculate(const unsigned long millis,
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

    double O2Toxicity::getCNSSlope(const double pO2)
    {
        if (pO2 <= 0.5)
            return 0.0;
        if (pO2 <= 0.6)
            return -1800.0;
        if (pO2 <= 0.7)
            return -1500.0;
        if (pO2 <= 0.8)
            return -1200.0;
        else
            return 0.0;

        return 0.0;
    }

    double O2Toxicity::getCNSIntercept(const double pO2)
    {
        return 0.0;
    }
}
