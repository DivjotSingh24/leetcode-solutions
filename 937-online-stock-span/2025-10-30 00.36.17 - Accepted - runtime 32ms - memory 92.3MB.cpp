class StockSpanner {
public:
    stack<pair<int, int>> market;
    StockSpanner() {
        stack<pair<int, int>> init;
        market = init;
    }
    
    int next(int price) {
        int cur=1;
        while(!market.empty() && market.top().first <= price){
            cur += market.top().second;
            market.pop();
        }
        market.push({price, cur});
        return cur;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */