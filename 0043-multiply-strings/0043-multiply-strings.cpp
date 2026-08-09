class Solution {
public:
    string addStrings(string a, string b) {
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        string ans = "0";
        int zeros = 0;

        for (int i = num2.size() - 1; i >= 0; i--) {
            int digit = num2[i] - '0';

            string cur = "";
            int carry = 0;

            for (int j = num1.size() - 1; j >= 0; j--) {
                int prod = digit * (num1[j] - '0') + carry;

                cur.push_back(prod % 10 + '0');
                carry = prod / 10;
            }

            if (carry)
                cur.push_back(carry + '0');

            reverse(cur.begin(), cur.end());

            // add trailing zeros
            cur.append(zeros, '0');
            zeros++;

            ans = addStrings(ans, cur);
        }

        return ans;
    }
};