class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m + n - 1; i >= n; --i) {
            nums1[i] = nums1[i - n];
        }
        int i = 0, i1 = n, i2 = 0;
        while (i1 < m + n || i2 < n) {
            int n1 = i1 < m + n ? nums1[i1] : INT_MAX;
            int n2 = i2 < n ? nums2[i2] : INT_MAX;
            if (n1 < n2) {
                nums1[i++] = n1;
                ++i1;
            } else {
                nums1[i++] = n2;
                ++i2;
            }
        }
    }
};
