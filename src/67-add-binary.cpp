class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int i = a.size() - 1, j = b.size() - 1;
        int sum = 0, carry = 0;
        while (i > -1 || j > -1 || carry) {
            int n1 = i > -1 ? a[i] - '0' : 0;
            int n2 = j > -1 ? b[j] - '0' : 0;
            sum = (n1 + n2 + carry) % 2;
            carry = (n1 + n2 + carry) / 2;
            s.push_back(sum + '0');
            --i;
            --j;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
