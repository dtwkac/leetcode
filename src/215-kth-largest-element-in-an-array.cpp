class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> max_heap;
        for (int i : nums) {
            max_heap.push(i);
        }
        for (int i = 0; i < k - 1; ++i) {
            max_heap.pop();
        }
        return max_heap.top();
    }
};
