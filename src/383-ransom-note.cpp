class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (char i : magazine) {
            ++m[i];
        }
        for (char i : ransomNote) {
            if (m.find(i) == m.cend() || m[i] == 0) {
                return false;
            }
            --m[i];
        }
        return true;
    }
};
