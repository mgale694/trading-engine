#ifndef TRADING_ENGINE_TRADER_H
#define TRADING_ENGINE_TRADER_H

#include "order.h"
#include "orderBook.h"

#include <vector>

namespace TradingEngine
{
    class Trader
    {
    public:
        Trader(const std::string &id, const std::string &name);
        Trader(const std::string &id, const std::string &name, OrderFactory *, OrderBook *);

        std::string getId() const;
        std::string getName() const;

        // TODO: create Stock class to hold stock meta (id, symbol)
        void buy(std::string stockId, std::string symbol, double price, int quantity);
        void sell(std::string stockId, std::string symbol, double price, int quantity);
        // void buy(const Stock &, int);
        // void sell(const Stock &, int);

        // void trade(double, double, int, int);
        // int getID() const;
        // const std::vector<std::shared_ptr<Order>> &getOrders() const;
        // void addStock(const Stock &);
        // std::vector<Stock> getStocks() const;

    private:
        const std::string &id;
        const std::string &name;
        // std::vector<Stock> stocks;
        OrderFactory *orderFactory;
        OrderBook *orderBook;
        std::vector<std::shared_ptr<Order>> orders;
    };
}

#endif // TRADING_ENGINE_TRADER_H