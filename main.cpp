#include "include/orderBook.h"
#include "include/trader.h"
#include "include/uuid.h"

#include <iostream>
#include <random>
#include <sstream>

using namespace TradingEngine;

int main()
{
    // Initialize the order book
    OrderBook orderBook;

    // Parameters
    int N = 10; // Number of traders
    int M = 50; // Number of trades per trader

    std::vector<std::string> symbols = {"AAPL", "TSLA", "GOOG", "ALPH", "TELE"};
    std::vector<double> basePrices = {150.0, 50.0, 100.0, 120.0, 200.0};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> symbolDist(0, symbols.size() - 1);
    std::uniform_int_distribution<> orderTypeDist(0, 1); // 0: BUY, 1: SELL
    std::uniform_int_distribution<> quantityDist(1, 100);
    std::uniform_real_distribution<> priceDeltaDist(-0.5, 0.5);

    for (int i = 0; i < N; ++i)
    {
        std::string traderId = uuid();
        std::string traderName = "Trader" + std::to_string(i + 1);
        Trader trader(traderId, traderName);

        std::cout << "Trader initialized with ID: " << trader.getId() << ", Name: " << trader.getName() << std::endl;

        for (int j = 0; j < M; ++j)
        {
            int symbolIdx = symbolDist(gen);
            std::string stockId = uuid();
            std::string stockSymbol = symbols[symbolIdx];
            double basePrice = basePrices[symbolIdx];
            double priceDelta = std::round(priceDeltaDist(gen) * 10.0) / 10.0; // round to nearest 0.1
            double stockPrice = basePrice + priceDelta;
            int quantity = quantityDist(gen);

            std::string orderId = uuid();
            std::shared_ptr<Order> order = std::make_shared<MarketOrder>(
                orderId, trader.getId(), stockId, stockSymbol, stockPrice, quantity);

            if (orderTypeDist(gen) == 0)
            {
                order->setOrderType(OrderType::BUY);
            }
            else
            {
                order->setOrderType(OrderType::SELL);
            }

            orderBook.addOrder(order);
        }
    }

    // Print the order book after all trading is done
    orderBook.tradeHistorySummary();
    orderBook.orderBookSummary();

    return 0;
}