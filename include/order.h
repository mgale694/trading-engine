#ifndef TRADING_ENGINE_ORDER_H
#define TRADING_ENGINE_ORDER_H

#include <string>
#include <memory>
#include <vector>
#include <ctime>

enum OrderType
{
    BUY,
    SELL
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
        Order(std::string traderId, std::string id, std::string symbol, double price, double quantity);

        std::string getTraderId() const;
        std::string getId() const;
        std::string getSymbol() const;
        double getPrice() const;
        double getQuantity() const;
        std::time_t getTimestamp() const;
        OrderType getOrdertype() const;
        void setOrderType(OrderType);

        void setQuantity(double newQuantity);

    private:
        std::string traderId;
        std::string id;
        std::string symbol;
        double price;
        double quantity;
        std::time_t timestamp;
        OrderType orderType;
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