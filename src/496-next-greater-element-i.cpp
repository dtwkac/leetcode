class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int i = nums2.size() - 1; i > -1; --i) {
            while (!s.empty() && nums2[i] > s.top()) {
                s.pop();
            }
            m[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        vector<int> v(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            v[i] = m[nums1[i]];
        }
        return v;
    }
};
