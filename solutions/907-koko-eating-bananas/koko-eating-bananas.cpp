class Solution {
public:
    bool isval(long mid,vector<int>& piles,int h){
        if(mid==0){return false;}
        long long cnt=0;
        for(int i: piles){if(i%mid>0){cnt+=(i/mid+1);}else{cnt+=(i/mid);}}
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r=1e9;
        int l=0;
        int mid=l+(r-l)/2;
        while(l<r){
            mid=l+(r-l)/2;
            if(isval(mid,piles,h)){r=mid;}
            else{l=mid+1;}
        }
        return l+(r-l)/2;
    }
};