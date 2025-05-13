#include "../include/orderBook.h"

#include <iostream>
#include <algorithm>

using namespace TradingEngine;

OrderBook::OrderBook() : strategy(nullptr) {}

void OrderBook::addOrder(std::shared_ptr<Order> order)
{
    book.push_back(order);
}

void OrderBook::matchOrders()
{
    std::vector<std::shared_ptr<Order>> buyOrders;
    std::vector<std::shared_ptr<Order>> sellOrders;

    // Create vectors of shared pointers to orders
    for (const auto &order : book)
    {
        if (order->getPrice() > 0)
        {
            buyOrders.push_back(std::static_pointer_cast<Order>(order));
        }
        else
        {
            sellOrders.push_back(std::static_pointer_cast<Order>(order));
        }
    }

    // Call the matching strategy with the separated buy and sell order vectors
    strategy->matchOrders(buyOrders, sellOrders);

    // Update the order book with remaining orders
    book.clear();
    book.insert(book.end(), buyOrders.begin(), buyOrders.end());
    book.insert(book.end(), sellOrders.begin(), sellOrders.end());
}

void OrderBook::setStrategy(OrderMatchingStrategy *newStrategy)
{
    strategy = newStrategy;
}

// void OrderBook::showMarketDepth() const
// {
//     std::cout << "Market Depth:" << std::endl;
//     std::cout << "Buy Orders:" << std::endl;
//     for (const auto &order : book)
//     {
//         if (order->isBuyOrder())
//         {
//             std::cout << "Price: " << order->getPrice() << ", Quantity: " << order->getQuantity() << std::endl;
//         }
//     }
//     std::cout << "Sell Orders:" << std::endl;
//     for (const auto &order : book)
//     {
//         if (!order->isBuyOrder())
//         {
//             std::cout << "Price: " << order->getPrice() << ", Quantity: " << order->getQuantity() << std::endl;
//         }
//     }
// }

// void OrderBook::showBuySellSpreads() const
// {
//     double highestBuy = -1;
//     double lowestSell = std::numeric_limits<double>::max();

//     for (const auto &order : book)
//     {
//         if (order->isBuyOrder())
//         {
//             highestBuy = std::max(highestBuy, order->getPrice());
//         }
//         else
//         {
//             lowestSell = std::min(lowestSell, order->getPrice());
//         }
//     }

//     if (highestBuy == -1 || lowestSell == std::numeric_limits<double>::max())
//     {
//         std::cout << "Insufficient data to calculate spreads." << std::endl;
//     }
//     else
//     {
//         std::cout << "Buy-Sell Spread: " << (lowestSell - highestBuy) << std::endl;
//     }
// }

void OrderBook::orderBookSummary() const
{
    std::cout << "Order Book Summary:" << std::endl;
    // showMarketDepth();
    // showBuySellSpreads();

    std::cout << "ID\tPrice\tQuantity\tOrder Type\n";
    for (const auto &order : book)
    {
        std::string orderTypeName = (order->getOrdertype() == OrderType::BUY) ? "Buy" : "Sell";
        std::cout << order->getId() << "\t" << order->getPrice() << "\t" << order->getQuantity() << "\t\t" << orderTypeName << "\n";
    }
    std::cout << "\n";
}