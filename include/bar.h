#pragma once

#include <string>

namespace backtester 
{
    struct Bar 
    {
        std::string date;
        double close;
        double high;
        double low;
        double open;
        long volume;
    };
} // namespace backtester
