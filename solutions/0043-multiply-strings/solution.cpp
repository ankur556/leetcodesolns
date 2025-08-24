#include <string>
using namespace std;

string add(string num1, string num2) {
    string result;
    int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += (num1[i--] - '0');
        if (j >= 0) sum += (num2[j--] - '0');
        
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    
    reverse(result.begin(), result.end());
    return result;
}




class Solution {
public:
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    
    int n1 = num1.size(), n2 = num2.size();
    vector<int> result(n1 + n2, 0);
    
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    
    string product;
    int i = 0;
    while (i < result.size() && result[i] == 0) i++; // skip leading zeros
    
    while (i < result.size()) product.push_back(result[i++] + '0');
    
    return product;
}

};
