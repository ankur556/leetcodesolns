class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==0||k==0){return 0;}
        if(k>n/2){
            int maxprofit=0;
            for(int i=1;i<prices.size();i++){
                if(prices[i]>prices[i-1]){maxprofit+=(prices[i]-prices[i-1]);}
            }
            return maxprofit;
        }
        //cout<<"! after this 1"<<endl;
        //fine till here
        vector<int> buy(k+1,INT_MIN);
        vector<int> sell(k+1,0);
        sell[0]=0;buy[0]=0;
        for(int p:prices){
            for(int i=1;i<=k;i++){
                buy[i]=max(buy[i],sell[i-1]-p);
                sell[i]=max(sell[i],buy[i]+p);
            }
        }
        //cout<<"! after this 2"<<endl;
        return sell[k];
    }
};