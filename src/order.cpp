#include "../include/order.h"

#include <iostream>

using namespace TradingEngine;

Order::Order(std::string traderId, std::string id, std::string symbol, double price, double quantity)
    : traderId(traderId), id(id), price(price), quantity(quantity) {}

std::string Order::getTraderId() const
{
    return traderId;
}

std::string Order::getId() const
{
    return id;
}

std::string Order::getSymbol() const
{
    return symbol;
}

double Order::getPrice() const
{
    return price;
}

double Order::getQuantity() const
{
    return quantity;
}

std::time_t Order::getTimestamp() const
{
    return timestamp;
}

OrderType Order::getOrdertype() const
{
    return orderType;
}

void Order::setOrderType(OrderType type)
{
    orderType = type;
}

OrderMatchingStrategy::~OrderMatchingStrategy()
{
}

void PriceTimeOrderMatchingStrategy::matchOrders(std::vector<std::shared_ptr<Order>> &buyOrders, std::vector<std::shared_ptr<Order>> &sellOrders)
{
    std::vector<std::shared_ptr<Order>> matchedOrders;

    for (auto sellOrder = sellOrders.begin(); sellOrder != sellOrders.end(); ++sellOrder)
    {
        for (auto it = buyOrders.begin(); it != buyOrders.end();)
        {
            if ((*sellOrder)->getPrice() <= (*it)->getPrice())
            {
                matchedOrders.push_back(*it);
                it = buyOrders.erase(it); // Remove the matched buy order
            }
            else
            {
                ++it;
            }
        }
    }

    // Update the buyOrders vector with remaining unmatched orders
    buyOrders.insert(buyOrders.end(), matchedOrders.begin(), matchedOrders.end());
}