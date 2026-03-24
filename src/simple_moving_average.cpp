#include "strategies/simple_moving_average.h"

namespace backtester
{
    SMAStrategy::SMAStrategy(int short_period, int long_period) : d_short_period{short_period}, d_long_period{long_period} {};

    Signal SMAStrategy::generate_signal(const std::vector<Bar>& bars, int index)
    {
        if (index < d_long_period - 1){
            return Signal::HOLD;
        }

        double short_sma = average(bars, index, d_short_period);
        double long_sma = average(bars, index, d_long_period);

        double yesterday_short_sma = average(bars, index - 1, d_short_period);
        double yesterday_long_sma = average(bars, index - 1, d_long_period);

        if (yesterday_short_sma <= yesterday_long_sma && short_sma > long_sma) {
            return Signal::BUY;
        } else if (yesterday_short_sma >= yesterday_long_sma && short_sma < long_sma) {
            return Signal::SELL;
        }
        return Signal::HOLD;
    }

    double SMAStrategy::average(const std::vector<Bar>& bars, int index, int lookback)
    {
        double output{0};
        for (int i = index; i > index - lookback; i--)
        {
            output += bars[i].d_close;
        }
        return output / lookback;
    }

} // namespace backtester
