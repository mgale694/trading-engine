#include "../include/orderBook.h"

#include <iostream>
#include <algorithm>

using namespace TradingEngine;

// OrderBook::OrderBook() : strategy(nullptr) {}

void OrderBook::addOrder(std::shared_ptr<Order> order)
{
    book.push_back(order);
}

void OrderBook::matchOrders()
{
    // ...existing code...
    if (strategy)
    {
        strategy->match(book);
    }
}

// void OrderBook::setStrategy(OrderMatchingStrategy *newStrategy)
// {
//     // ...existing code...
//     strategy = newStrategy;
// }

void OrderBook::showMarketDepth() const
{
    std::cout << "Market Depth:" << std::endl;
    std::cout << "Buy Orders:" << std::endl;
    for (const auto &order : book)
    {
        if (order->isBuyOrder())
        {
            std::cout << "Price: " << order->getPrice() << ", Quantity: " << order->getQuantity() << std::endl;
        }
    }
    std::cout << "Sell Orders:" << std::endl;
    for (const auto &order : book)
    {
        if (!order->isBuyOrder())
        {
            std::cout << "Price: " << order->getPrice() << ", Quantity: " << order->getQuantity() << std::endl;
        }
    }
}

void OrderBook::showBuySellSpreads() const
{
    double highestBuy = -1;
    double lowestSell = std::numeric_limits<double>::max();

    for (const auto &order : book)
    {
        if (order->isBuyOrder())
        {
            highestBuy = std::max(highestBuy, order->getPrice());
        }
        else
        {
            lowestSell = std::min(lowestSell, order->getPrice());
        }
    }

    if (highestBuy == -1 || lowestSell == std::numeric_limits<double>::max())
    {
        std::cout << "Insufficient data to calculate spreads." << std::endl;
    }
    else
    {
        std::cout << "Buy-Sell Spread: " << (lowestSell - highestBuy) << std::endl;
    }
}

void OrderBook::printOrderBook() const
{
    std::cout << "Order Book Summary:" << std::endl;
    showMarketDepth();
    showBuySellSpreads();

    double totalBuy = 0, totalSell = 0;
    for (const auto &order : book)
    {
        if (order->isBuyOrder())
        {
            totalBuy += order->getQuantity();
        }
        else
        {
            totalSell += order->getQuantity();
        }
    }

    std::cout << "Total Buy Quantity: " << totalBuy << std::endl;
    std::cout << "Total Sell Quantity: " << totalSell << std::endl;
}