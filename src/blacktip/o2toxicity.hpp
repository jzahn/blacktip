#ifndef O2TOXICITY_H
#define O2TOXICITY_H

#include "mix.hpp"

struct CNSCoefficients
{
    const double slope = 0.0;
    const double intercept = 0.0;
};

namespace blacktip
{
    class O2Toxicity
    {
    private:
        double pO2 = 0.0;
        double cnsToxicity = 0.0; // unit OTU
        double pulmonaryToxicity = 0.0; // unit OTU

        static CNSCoefficients getCNSCoefficients(double pO2);

    public:
        void calculate(unsigned long millis, double depth,
				const Mix &mix);
        void reset();
        double getPO2() const {return pO2;}
        double getCNSToxicity() const {return cnsToxicity;}
        double getPulmonaryToxicity() const {return pulmonaryToxicity;}
    };
}

#endif
