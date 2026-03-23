# practicing-cpp-mini-backtester

_Note: given the educational nature of this project, code was written archaically by hand - no "vibing"_

Mini project to practice C++ skills. Reads a CSV file of historical stock data and runs different trading strategies against it to compare historical performance.

## Trading Rules

- You start with a fixed cash balance (e.g. $10,000)
- You can only hold **one position at a time** — you're either all-in or all-out
- **Buy** = spend all cash to purchase shares at today's close price
- **Sell** = sell all shares at today's close price, back to cash
- **Hold** = do nothing
- If you're already holding and the strategy says Buy, it's ignored
- If you're not holding and the strategy says Sell, it's ignored
- No shorting, no partial positions, no leverage, no options
- No transaction fees or slippage

## Strategies

1. **Buy and Hold** — buy on day 1, sell on last day
2. **SMA Crossover** — buy when short moving average crosses above long moving average, sell on the opposite
3. **Mean Reversion** — buy when price drops below N-day average by K standard deviations, sell when it returns

## Output

For each strategy, print:
- Total return (%)
- Number of trades
- Win rate (% of trades that were profitable)
- Max drawdown (largest peak-to-trough decline while holding)

## Input

- Single CSV file of daily OHLCV data (Date, Open, High, Low, Close, Volume)
- One row = one trading day

## Out of Scope

- No live data fetching
- No intraday trading
- No portfolio (multiple stocks)
- No order types (market only, at close)
- No persistence or GUI
- No parameter optimization