class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0, b = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            int temp = a;
            a = b;
            b = min(temp + cost[i - 2], b + cost[i - 1]);
        }
        return b;
    }
};
