class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size(), size = size1 + size2;
        if (size1 > size2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0, high = size1;
        int nums1_left_end = 0, nums1_right_start = 0, nums2_left_end = 0,
            nums2_right_start = 0;
        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = size / 2 - i;
            nums1_left_end = i - 1 > -1 ? nums1[i - 1] : INT_MIN;
            nums1_right_start = i < size1 ? nums1[i] : INT_MAX;
            nums2_left_end = j - 1 > -1 ? nums2[j - 1] : INT_MIN;
            nums2_right_start = j < size2 ? nums2[j] : INT_MAX;
            if (nums1_left_end > nums2_right_start) {
                high = i - 1;
            } else if (nums2_left_end > nums1_right_start) {
                low = i + 1;
            } else {
                break;
            }
        }
        int left_max = max(nums1_left_end, nums2_left_end);
        int right_min = min(nums1_right_start, nums2_right_start);
        return size & 1 ? right_min : (left_max + right_min) / 2.0;
    }
};
