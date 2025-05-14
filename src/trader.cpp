#include "../include/trader.h"

#include <iostream>
#include <algorithm>

using namespace TradingEngine;

Trader::Trader(const std::string &id, const std::string &name)
    : id(id), name(name), orderFactory(nullptr), orderBook(nullptr) {}

Trader::Trader(const std::string &id, const std::string &name, OrderFactory *orderFactory, OrderBook *orderBook)
    : id(id), name(name), orderFactory(orderFactory), orderBook(orderBook) {}

std::string Trader::getId() const
{
    return id;
}

std::string Trader::getName() const
{
    return name;
}

void Trader::buy(std::string stockId, std::string symbol, double price, int quantity)
{
    try
    {
        if (orderFactory != nullptr && orderBook != nullptr)
        {
            std::shared_ptr<Order> ord = orderFactory->createOrder("GEN_ORDER_ID", id, stockId, symbol, price, quantity);
            orders.push_back(ord);
            if (ord != nullptr)
            {
                orderBook->addOrder(ord);
            }
        }
    }
    // catch (const TraderException& e) {
    // 	// Handle trader-specific exceptions
    // 	std::cerr << "Trader Exception: " << e.what() << std::endl;
    // }
    catch (const std::exception &e)
    {
        // Handle other exceptions (if any)
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Trader::sell(std::string stockId, std::string symbol, double price, int quantity)
{
    try
    {
        if (orderFactory != nullptr && orderBook != nullptr)
        {
            std::shared_ptr<Order> ord = orderFactory->createOrder("GEN_ORDER_ID", id, stockId, symbol, -price, quantity);
            orders.push_back(ord);
            if (ord != nullptr)
            {
                orderBook->addOrder(ord);
            }
        }
    }
    // catch (const TraderException &e)
    // {
    //     // Handle trader-specific exceptions
    //     std::cerr << "Trader Exception: " << e.what() << std::endl;
    // }
    catch (const std::exception &e)
    {
        // Handle other exceptions (if any)
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
