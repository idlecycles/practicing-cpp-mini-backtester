#include "stats.h"
#include <vector>

namespace backtester
{
    Stats compute_stats(const std::vector<Trade>& trades)
    {
        int num_trades = trades.size();
        if (!num_trades)
        {
            return Stats{};
        }
        int profitable_trades = 0;
        double total_return = 1;
        for (const auto& trade : trades)
        {
            if (trade.buy_price < trade.sell_price) {
                ++profitable_trades;
            }
            total_return *= (1 + ((trade.sell_price - trade.buy_price) / trade.buy_price));
        }

        double win_rate = static_cast<double>(profitable_trades) / num_trades;
        return Stats{(total_return - 1.0) * 100, num_trades, win_rate};
    }

} // namespace backtester
