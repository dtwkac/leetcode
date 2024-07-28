class StockSpanner {
public:
    StockSpanner() {
        i = 0;
        s.push({i++, INT_MAX});
    }

    int next(int price) {
        while (price >= s.top().second) {
            s.pop();
        }
        int ans = i - s.top().first;
        s.push({i++, price});
        return ans;
    }

private:
    stack<pair<int, int>> s;
    int i;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
