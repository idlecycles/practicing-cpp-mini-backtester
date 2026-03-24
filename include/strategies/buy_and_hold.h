#pragma once

#include "bar.h"
#include "strategy.h"
#include "signal.h"

#include <vector>

namespace backtester
{
    class BuyAndHoldStrategy: public Strategy
    {
        public:
            Signal generate_signal(const std::vector<Bar>& bars, int index) override 
            {
                if (index == 0)
                {
                    return Signal::BUY;
                }
                return Signal::HOLD;
            };
    };

} // namespace backtesterss
