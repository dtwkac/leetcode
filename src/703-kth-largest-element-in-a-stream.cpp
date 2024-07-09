class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) {
                min_heap.push(nums[i]);
            } else if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if (min_heap.size() < m_k) {
            min_heap.push(val);
        } else if (val > min_heap.top()) {
            min_heap.pop();
            min_heap.push(val);
        }
        return min_heap.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int m_k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
