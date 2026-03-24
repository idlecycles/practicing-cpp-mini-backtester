#include "engine.h"

#include <vector>

namespace backtester
{
    Engine::Engine(std::unique_ptr<Strategy> strategy, std::vector<Bar> bars) : d_strategy{std::move(strategy)}, d_bars{std::move(bars)} {}

    std::vector<Trade> Engine::run()
    {
        auto trades = std::vector<Trade>{};
        int index = 0;
        bool is_holding = false;
        std::string buy_date{};
        double buy_price{};

        for (const auto &bar : d_bars)
        {
            Signal signal = d_strategy->generate_signal(d_bars, index);
            if (signal == Signal::BUY && !is_holding) {
                buy_date = bar.d_date;
                buy_price = bar.d_close;
                is_holding = true;
            } else if (signal == Signal::SELL && is_holding) {
                trades.emplace_back(Trade{buy_date, buy_price, bar.d_date, bar.d_close});
                is_holding = false;
            }
            ++index;
        }

        if (is_holding){
            is_holding = false;
            trades.emplace_back(Trade{buy_date, buy_price, d_bars.back().d_date, d_bars.back().d_close});
        }
        return trades;
    }

} // namespace backtester
