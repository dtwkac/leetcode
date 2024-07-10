class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int i = 0, j = 0, max = 0;
        while (j < s.size()) {
            if (set.find(s[j]) == set.cend()) {
                set.insert(s[j++]);
            } else {
                while (set.find(s[j]) != set.cend()) {
                    set.erase(s[i++]);
                }
            }
            int length = j - i;
            max = length > max ? length : max;
        }
        return max;
    }
};
