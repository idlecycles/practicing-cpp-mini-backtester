#pragma once

#include "trade.h"
#include <vector>

namespace backtester
{
    struct Stats
    {
        double total_return;
        int num_trades;
        double win_rate;
        double max_drawdown;
    };

    Stats compute_stats(const std::vector<Trade>& trades);

} // namespace backtester
