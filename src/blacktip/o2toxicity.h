#ifndef O2TOXICITY_H
#define O2TOXICITY_H

#include "mix.h"

namespace blacktip
{
    class O2ToxicityMeter
    {
    private:

    public:
        void calculate(const unsigned long millis, const double depth,
				const Mix &mix);
    };
}

#endif
