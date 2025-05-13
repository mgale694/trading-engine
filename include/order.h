#ifndef ORDER_H
#define ORDER_H

#include <string>

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
        Order(std::string id, double price, double quantity, bool isBuyOrder);

        std::string getId() const;
        double getPrice() const;
        double getQuantity() const;
        bool isBuyOrder() const;

        void setQuantity(double newQuantity);

    private:
        std::string id;
        double price;
        double quantity;
        bool buyOrder;
    };
}

#endif // ORDER_H
