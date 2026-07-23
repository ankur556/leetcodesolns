class Solution {
public:
    bool isval(long long ver,vector<int> piles, int tar){
        long long cur=0;
        if(ver==0){return false;}
        for(int i: piles){
            cur+=i/ver;if(i%ver!=0){cur++;}
        }
        return cur<=tar;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      long long r=1e9;long long l=0;
      long mid=l+(r-l)/2;
      while(l<r){
        mid=l+(r-l)/2;
        if(isval(mid,piles,h)){r=mid;}
        else{l=mid+1;}
      }  
      return l;
    }
};