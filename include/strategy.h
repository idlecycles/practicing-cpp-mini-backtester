#pragma once

#include "signal.h"
#include "bar.h"

#include <vector>

namespace backtester
{
    class Strategy
    {
        public:
            virtual Signal generate_signal(const std::vector<Bar>& bars, int index) = 0;
            virtual ~Strategy() = default;
    };

} // namespace backtester
