#include "../include/order.h"

#include <iostream>

using namespace TradingEngine;

Order::Order(std::string id, std::string traderId, std::string stockId, std::string symbol, double price, double quantity)
    : id(id), traderId(traderId), stockId(stockId), symbol(symbol), price(price), quantity(quantity) {}

// Add the virtual destructor definition
Order::~Order() {}

std::string Order::getId() const
{
    return id;
}

std::string Order::getTraderId() const
{
    return traderId;
}

std::string Order::getStockId() const
{
    return stockId;
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

OrderType Order::getOrderType() const
{
    return orderType;
}

void Order::setOrderType(OrderType type)
{
    orderType = type;
}

OrderType MarketOrder::getOrderFactoryType() const
{
    return OrderType::MARKET;
}

OrderType LimitOrder::getOrderFactoryType() const
{
    return OrderType::LIMIT;
}

OrderFactory::~OrderFactory()
{
}

std::unique_ptr<Order> MarketOrderFactory::createOrder(std::string id, std::string traderId, std::string stockId, std::string symbol, double price, int quantity)
{
    return std::make_unique<MarketOrder>(id, traderId, stockId, symbol, price, quantity);
}

std::unique_ptr<Order> LimitOrderFactory::createOrder(std::string id, std::string traderId, std::string stockId, std::string symbol, double price, int quantity)
{
    return std::make_unique<LimitOrder>(id, traderId, stockId, symbol, price, quantity);
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