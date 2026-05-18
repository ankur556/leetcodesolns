class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min_till=1e7;
       int val=0;
       for(int i: prices){
       if(i<min_till){min_till=i;}
       if(val<i-min_till){val=i-min_till;}
       } 
        return val;
    }
   
};
