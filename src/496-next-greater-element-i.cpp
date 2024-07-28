class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        s.push(INT_MAX);
        for (int i = 0; i < nums2.size(); ++i) {
            m[nums2[i]] = -1;
            while (nums2[i] > s.top()) {
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        vector<int> v;
        for (int i : nums1) {
            v.push_back(m[i]);
        }
        return v;
    }
};
