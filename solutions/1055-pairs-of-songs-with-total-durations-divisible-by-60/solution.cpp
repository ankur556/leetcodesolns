class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(int i=0;i<time.size();i++){time[i]%=60;}
        unordered_map<int,int>a;
        for(int i: time){a[i]++;}
        int sol=0;
        for(int i=1;i<30;i++){sol+=(a[i]*a[60-i]);}
        int k=a[30];
        int pick=((k-1)*(k))/2;
        sol+=pick;
         k=a[0];
         if(k%2==0){pick=((k-1)*(k/2));}
         else{pick=(((k-1)/2)*(k));}
         sol+=pick;
        return sol;
    }
};
