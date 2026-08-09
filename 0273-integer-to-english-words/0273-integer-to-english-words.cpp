class Solution {
public:
    vector<string> below20 = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
        "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string helper(int num) {
        if (num == 0)
            return "";

        if (num < 20)
            return below20[num] + " ";

        if (num < 100)
            return tens[num / 10] + " " + helper(num % 10);

        if (num < 1000)
            return below20[num / 100] + " Hundred " + helper(num % 100);

        if (num < 1000000)
            return helper(num / 1000) + "Thousand " + helper(num % 1000);

        if (num < 1000000000)
            return helper(num / 1000000) + "Million " + helper(num % 1000000);

        return helper(num / 1000000000) + "Billion " +
               helper(num % 1000000000);
    }

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        string ans = helper(num);

        while (!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};