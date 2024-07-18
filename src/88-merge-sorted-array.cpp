class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1, i2 = n - 1, i = m + n - 1;
        while (i1 > -1 || i2 > -1) {
            int n1 = i1 > -1 ? nums1[i1] : INT_MIN;
            int n2 = i2 > -1 ? nums2[i2] : INT_MIN;
            if (n1 > n2) {
                nums1[i--] = n1;
                --i1;
            } else {
                nums1[i--] = n2;
                --i2;
            }
        }
    }
};
