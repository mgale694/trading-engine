#include "../include/order.h"

namespace TradingEngine
{
    Order::Order(double price, double quantity, bool isBuyOrder)
        : price(price), quantity(quantity), buyOrder(isBuyOrder) {}

    double Order::getPrice() const
    {
        return price;
    }

    double Order::getQuantity() const
    {
        return quantity;
    }

    bool Order::isBuyOrder() const
    {
        return buyOrder;
    }

    void Order::setQuantity(double newQuantity)
    {
        quantity = newQuantity;
    }
}
