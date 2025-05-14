#ifndef TRADING_ENGINE_ORDERBOOK_H
#define TRADING_ENGINE_ORDERBOOK_H

#include "order.h"

#include <vector>

namespace TradingEngine
{
    class OrderBook
    {
    public:
        OrderBook();
        void addOrder(std::shared_ptr<Order>);
        void matchOrders();
        void setStrategy(OrderMatchingStrategy *);
        // void showMarketDepth() const;
        // void showBuySellSpreads() const;
        void orderBookSummary() const;

    private:
        std::vector<std::shared_ptr<Order>> book;
        OrderMatchingStrategy *strategy;
    };
}
#endif // TRADING_ENGINE_ORDERBOOK_H