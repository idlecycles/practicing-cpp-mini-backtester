#pragma once

#include <string>

namespace backtester
{
    struct Trade 
    {
        std::string buy_date;
        double buy_price;
        std::string sell_date;
        double sell_price;
    };
} // namespace backtester
