class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_till=prices[0];
        int max_pro=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min_till){min_till=prices[i];}
            if(prices[i]-min_till>max_pro){max_pro=prices[i]-min_till;}
        }
        return max_pro;
    }
};
