class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, buy = INT_MAX;
        for (int i : prices) {
            buy = i < buy ? i : buy;
            int profit = i - buy;
            max = profit > max ? profit : max;
        }
        return max;
    }
};
