#pragma once

#include "strategy.h"
#include "trade.h"
#include "bar.h"

#include <memory>
#include <vector>

namespace backtester
{
    class Engine
    {
    public:
        Engine(std::unique_ptr<Strategy> strategy, std::vector<Bar> bars);
        std::vector<Trade> run();

    private:
        std::unique_ptr<Strategy> d_strategy;
        std::vector<Bar> d_bars;
    };

} // namespace backtester
