#include "include/orderBook.h"
#include "include/trader.h"
#include "include/uuid.h"

#include <iostream>
#include <random>
#include <sstream>

using namespace TradingEngine;

int main()
{
    // Initialize the order book
    OrderBook orderBook;

    // Example Trader
    // Generate a UUID for the trader
    std::string traderId = uuid();
    Trader trader(traderId, "Trader1");

    // Print the trader's ID and name
    std::cout << "Trader initialized with ID: " << trader.getId() << ", Name: " << trader.getName() << std::endl;

    int quantity1 = 25;
    // stock info
    std::string stockId1 = uuid();
    std::string stockSymbol1 = "AAPL";
    double stockPrice1 = 150.0;

    // Place buy
    std::string orderId1 = uuid();
    std::shared_ptr<Order> buyOrder = std::make_shared<MarketOrder>(orderId1, trader.getId(), stockId1, stockSymbol1, stockPrice1, quantity1);
    buyOrder->setOrderType(OrderType::BUY);

    orderBook.addOrder(buyOrder);

    int quantity2 = 35;
    // stock info
    std::string stockId2 = uuid();
    std::string stockSymbol2 = "TSLA";
    double stockPrice2 = 50.0;

    // Place sell order
    std::string orderId2 = uuid();
    std::shared_ptr<Order> sellOrder = std::make_shared<MarketOrder>(orderId2, trader.getId(), stockId2, stockSymbol2, stockPrice2, quantity2);
    sellOrder->setOrderType(OrderType::SELL);

    // trader.trade(150, 160, 12, 13);

    // Add orders to the order book
    orderBook.addOrder(sellOrder);

    // Print the order book after all trading is done
    orderBook.orderBookSummary();

    return 0;
}