class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (size <= 2 || numRows <= 1) {
            return s;
        }
        string ans;
        for (int row = 0; row < numRows; ++row) {
            int i = row;
            while (i < size) {
                ans += s[i];
                int j = i + 2 * numRows - 2 * row - 2;
                if (row > 0 && row < numRows - 1 && j < size) {
                    ans += s[j];
                }
                i += (2 * numRows - 2);
            }
        }
        return ans;
    }
};
