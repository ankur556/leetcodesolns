class Solution {
public:
    int maxProfit(vector<int>& a) {
        int min=a[0];
        int max=a[0];
        int maxp=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<min){min=a[i];max=a[i];}
            if(a[i]>max){max=a[i];}
            if(maxp<max-min){maxp=max-min;}
        }
        return maxp;
    }
};
