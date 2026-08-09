class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int k=prices.size()-1;int j=discounts.size()-1;
        double sum=0;
        while(k>=0&&j>=0){
            sum+=((double)(1.0*prices[k]*(double(100.0-discounts[j]))/(100.0)));k--;j--;
        } 
        while(k>=0){
            sum+=(1.0*prices[k]);k--;
        } 
        return sum; 
    }
};