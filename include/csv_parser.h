#pragma once

#include "bar.h"
#include <vector>

namespace backtester 
{
    std::vector<Bar> load_csv(const std::string& filename);
} // namespace backtester