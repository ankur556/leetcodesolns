class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        // Process both strings from right to left
        while (i >= 0 || j >= 0 || carry) {
            // Get the digit value, or 0 if we've run out of digits
            int d1 = (i >= 0) ? num1[i--] - '0' : 0;
            int d2 = (j >= 0) ? num2[j--] - '0' : 0;

            int sum = d1 + d2 + carry;
            res += to_string(sum % 10); // Append the last digit of sum
            carry = sum / 10;           // Keep the carry for next iteration
        }

        // The result is currently backwards, so reverse it
        reverse(res.begin(), res.end());
        return res;
    }
};
