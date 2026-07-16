class Solution {
public:
    bool isval(vector<int>& days,int val,int boq,int cont){
        int cur=0;
        for(int i=0;i<days.size();i++){
            if(days[i]<=val){cur++;}
            else{cur=0;}
            if(cur>=cont){boq--;cur=0;}
        }
        return boq<=0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size()){return -1;}
        int l=0;
        int r=1e9;
        int mid=l+(r-l)/2;
        while(l<r){
            mid=l+(r-l)/2;
            if(isval(bloomDay,mid,m,k)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};