#pragma once

#include <string>

namespace backtester 
{
    struct Bar 
    {
        std::string d_date;
        double d_close;
        double d_high;
        double d_low;
        double d_open;
        long d_volume;
    };
} // namespace backtester
