class Solution {
public:
    string toHex(int n) {
        if (n == 0) return "0"; 
        string sol;
        unsigned int num = n; 
        while (num > 0) {
            if (num % 16 >= 10) {
                sol.push_back('a' - 10 + num % 16);
            } else {
                sol.push_back('0' + num % 16);
            }
            num = num / 16;
        }
        for (int i = 0; i < sol.size() / 2; i++) {
            swap(sol[i], sol[sol.size() - i - 1]);
        }
        return sol;
    }
};
