#ifndef TRADING_ENGINE_ORDER_H
#define TRADING_ENGINE_ORDER_H

#include <string>
#include <memory>
#include <vector>
#include <ctime>

enum OrderType
{
    BUY,
    SELL,
    MARKET,
    LIMIT,
};

namespace TradingEngine
{
    // class Order
    // {
    // public:
    //     Order(int, double, int);
    //     virtual ~Order();
    //     virtual std::string getOrderType() const = 0;
    //     int getTraider_id() const;
    //     double getPrice() const;
    //     int getQuantity() const;
    //     std::time_t getTimestamp() const;
    //     void reduceQuantity(int);
    //     OrderType getOrdertype() const;
    //     void setOrderType(OrderType);

    // private:
    //     int traider_id;
    //     double price;
    //     int quantity;
    //     std::time_t timestamp;
    //     OrderType ordertype;
    // };

    class Order
    {
    public:
        Order(std::string id, std::string traderId, std::string stockId, std::string symbol, double price, double quantity);

        virtual ~Order();
        virtual OrderType getOrderFactoryType() const = 0;

        std::string getId() const;
        std::string getTraderId() const;
        std::string getStockId() const;
        std::string getSymbol() const;
        OrderType getOrderType() const;
        double getPrice() const;
        double getQuantity() const;
        std::time_t getTimestamp() const;

        void setOrderType(OrderType);
        void setQuantity(double newQuantity);

    private:
        std::string id;
        std::string traderId;
        std::string stockId;
        std::string symbol;
        double price;
        double quantity;
        std::time_t timestamp;
        OrderType orderType;
    };

    class MarketOrder : public Order
    {
    public:
        MarketOrder(std::string id, std::string traderId, std::string stockId, std::string symbol, double price, double quantity) : Order(id, traderId, stockId, symbol, price, quantity) {}
        OrderType getOrderFactoryType() const override;
    };

    class LimitOrder : public Order
    {
    public:
        LimitOrder(std::string id, std::string traderId, std::string stockId, std::string symbol, double price, double quantity) : Order(id, traderId, stockId, symbol, price, quantity) {}
        OrderType getOrderFactoryType() const override;
    };

    class OrderFactory
    {
    public:
        virtual std::unique_ptr<Order> createOrder(std::string, std::string, std::string, std::string, double, int) = 0;
        virtual ~OrderFactory();
    };

    class MarketOrderFactory : public OrderFactory
    {
    public:
        std::unique_ptr<Order> createOrder(std::string, std::string, std::string, std::string, double, int) override;
    };

    class LimitOrderFactory : public OrderFactory
    {
    public:
        std::unique_ptr<Order> createOrder(std::string, std::string, std::string, std::string, double, int) override;
    };

    class OrderMatchingStrategy
    {
    public:
        virtual void matchOrders(std::vector<std::shared_ptr<Order>> &, std::vector<std::shared_ptr<Order>> &) = 0;
        virtual ~OrderMatchingStrategy();
    };

    class PriceTimeOrderMatchingStrategy : public OrderMatchingStrategy
    {
    public:
        void matchOrders(std::vector<std::shared_ptr<Order>> &, std::vector<std::shared_ptr<Order>> &) override;
    };

}

#endif // TRADING_ENGINE_ORDER_H