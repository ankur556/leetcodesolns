class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st; 
        for (int i = prices.size() - 1; i >= 0; i--) {
            int currentPrice = prices[i]; 
            while (!st.empty() && st.top() > currentPrice) {
                st.pop();
            }
            if (!st.empty()) {
                prices[i] = currentPrice - st.top();
            }
            st.push(currentPrice);
        }
        
        return prices;
    }
};
