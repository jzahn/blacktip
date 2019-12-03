#ifndef O2TOXICITY_H
#define O2TOXICITY_H

#include "mix.h"

namespace blacktip
{
    class O2Toxicity
    {
    private:
        double pO2 = 0.0;
        double cnsToxicity = 0.0; // unit OTU
        double pulmonaryToxicity = 0.0; // unit OTU

        static double getCNSSlope(const double pO2);
        static double getCNSIntercept(const double pO2);

    public:
        void calculate(const unsigned long millis, const double depth,
				const Mix &mix);

        double getPO2() {return pO2;}
        double getCNSToxicity() {return cnsToxicity;}
        double getPulmonaryToxicity() {return pulmonaryToxicity;}
    };
}

#endif
