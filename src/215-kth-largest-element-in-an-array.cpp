class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i : nums) {
            if (min_heap.size() < k) {
                min_heap.push(i);
            } else if (i > min_heap.top()) {
                min_heap.pop();
                min_heap.push(i);
            }
        }
        return min_heap.top();
    }
};
