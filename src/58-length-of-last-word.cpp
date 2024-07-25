class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i > -1 && !isalpha(s[i])) {
            --i;
        }
        int j = i;
        while (j > -1 && isalpha(s[j])) {
            --j;
        }
        return i - j;
    }
};
