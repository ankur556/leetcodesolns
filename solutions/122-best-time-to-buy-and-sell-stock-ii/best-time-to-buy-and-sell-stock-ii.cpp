class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size());
        if(prices.size()==0){return 0;}
        int min=prices[0];
        int max=0;
        int cur=0;
        for(int i=1;i<prices.size();i++){
           if(prices[i]<min){max=prices[i];min=prices[i];}
           if(prices[i]>max){max=prices[i];}
           if(max-min){cur+=(max-min);max=prices[i];min=prices[i];}
        }
        return cur;

    }
};