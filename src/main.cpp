#include <iostream>
#include <memory>

#include "csv_parser.h"
#include "engine.h"
#include "stats.h"
#include "strategies/buy_and_hold.h"
#include "strategies/simple_moving_average.h"

int main() {
    auto bars = backtester::load_csv("../data/random.csv");

    // Buy and Hold
    auto bh_engine = backtester::Engine(
        std::make_unique<backtester::BuyAndHoldStrategy>(),
        bars
    );
    auto bh_trades = bh_engine.run();
    auto bh_stats = backtester::compute_stats(bh_trades);

    std::cout << "=== Buy and Hold ===\n";
    std::cout << "Total Return: " << bh_stats.total_return << "%\n";
    std::cout << "Trades: " << bh_stats.num_trades << "\n";
    std::cout << "Win Rate: " << bh_stats.win_rate * 100 << "%\n\n";

    // SMA Crossover
    auto sma_engine = backtester::Engine(
        std::make_unique<backtester::SMAStrategy>(20, 50),
        std::move(bars)
    );
    auto sma_trades = sma_engine.run();
    auto sma_stats = backtester::compute_stats(sma_trades);

    std::cout << "=== SMA Crossover (20/50) ===\n";
    std::cout << "Total Return: " << sma_stats.total_return << "%\n";
    std::cout << "Trades: " << sma_stats.num_trades << "\n";
    std::cout << "Win Rate: " << sma_stats.win_rate * 100 << "%\n";

    return 0;
}
