class Solution {
public:
    long long sumation(long long n){
        if(n==0){return 1;}
        else if(n==1){return 1;}
        else{return n*(n-1)/2;}
    }
    long long getDescentPeriods(vector<int>& prices) {
        vector<int> c;
        int curr=1;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i+1]==prices[i]-1){curr++;}
            else if(curr!=1){c.push_back(curr);curr=1;}
        }
        if(curr!=1){c.push_back(curr);}
        long long ans=prices.size();
        for(int i=0;i<c.size();i++){
            ans+=(sumation(c[i]));
        }
        return ans;
    }
};
