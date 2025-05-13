#include "../include/orderBook.h"

#include <iostream>

using namespace TradingEngine;

int main()
{
    // Initialize the order book
    OrderBook orderBook;

    // Print the order book after all trading is done
    orderBook.orderBookSummary();

    std::cout << "Finished!" << std::endl;
    return 0;
}