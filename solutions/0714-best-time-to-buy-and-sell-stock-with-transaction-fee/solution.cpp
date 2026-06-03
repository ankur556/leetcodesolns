class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n<2) return 0;

        int sell = 0;
        int skip = 0;
        int hold = -prices[0];

        int temp = sell;
        for (int i = 0; i < n; i++) {
            sell = hold+prices[i]-fee;
            hold = max(hold, max(temp, skip)-prices[i]);
            skip = max(skip, temp);

            temp = sell;
        }

        return max(sell, skip);
    }
};
