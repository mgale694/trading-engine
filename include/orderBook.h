namespace TradingEngine
{
    class OrderBook
    {
    public:
        OrderBook();
        void addOrder(std::shared_ptr<Order>);
        void matchOrders();
        // void setStrategy(OrderMatchingStrategy *);
        void showMarketDepth() const;
        void showBuySellSpreads() const;
        void printOrderBook() const;

    private:
        std::vector<std::shared_ptr<Order>> book;
        // OrderMatchingStrategy *strategy;
    };
}