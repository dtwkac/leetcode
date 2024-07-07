class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        int sum = 0, carry = 0;
        string s;
        while (i > -1 || j > -1 || carry) {
            int n1 = i > -1 ? num1[i] - '0' : 0;
            int n2 = j > -1 ? num2[j] - '0' : 0;
            sum = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;
            s.push_back(sum + '0');
            --i;
            --j;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
