#include "o2toxicity.h"

#include <cmath>

#include "utility.h"

namespace blacktip
{
    void O2Toxicity::calculate(const unsigned long millis,
            const double depth, const Mix &mix)
    {
        // calculate pO2
        double atm = (33.0 + depth) / 33.0;
        pO2 = mix.getFractionOxygen() * atm;

        // only accumulate o2 toxicity at pO2 > 0.5
        if (pO2 <= 0.5)
            return;

        // accumulate CNS toxicity
        CNSCoefficients cnsCoefficients = getCNSCoefficients(pO2);
        cnsToxicity += Utility::millisToMinutes(millis) /
                (cnsCoefficients.slope * pO2 + cnsCoefficients.intercept);

        // TODO accumulate Pulmonary toxicity for tec diving
        //pulmonaryToxicity += Utility::millisToMinutes(millis) * pow((0.5 / (pO2 - 0.5)), -0.8333);
    }

    void O2Toxicity::reset()
    {
        pO2 = 0.0;
        cnsToxicity = 0.0;
        pulmonaryToxicity = 0.0;
    }

    CNSCoefficients O2Toxicity::getCNSCoefficients(const double pO2)
    {
        if (pO2 <= 0.5)
            return {0.0, 0.0};
        if (pO2 <= 0.6)
            return {-1800.0, 1800.0};
        if (pO2 <= 0.7)
            return {-1500.0, 1620.0};
        if (pO2 <= 0.8)
            return {-1200.0, 1410.0};
        if (pO2 <= 0.9)
            return {-900.0, 1170.0};
        if (pO2 <= 1.1)
            return {-600.0, 900.0};
        if (pO2 <= 1.5)
            return {-300.0, 570.0};
        if (pO2 <= 1.6)
            return {-750.0, 1245.0};
        else
            return {0.0, 0.0};
    }
}
