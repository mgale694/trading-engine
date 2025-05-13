#include "../include/order.h"

#include <iostream>

using namespace TradingEngine;

Order::Order(std::string id, double price, double quantity)
    : id(id), price(price), quantity(quantity) {}

std::string Order::getId() const
{
    return id;
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
    return ordertype;
}

void Order::setOrderType(OrderType type)
{
    ordertype = type;
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