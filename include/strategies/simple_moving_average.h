#pragma once

#include "bar.h"
#include "strategy.h"
#include "signal.h"

#include <vector>

namespace backtester 
{
    class SMAStrategy: public Strategy
    {
        public:
            SMAStrategy(int short_period, int long_period);
            Signal generate_signal(const std::vector<Bar> &bars, int index) override;
        
        private:
            int d_short_period;
            int d_long_period;
    };

} // namespace backtester
