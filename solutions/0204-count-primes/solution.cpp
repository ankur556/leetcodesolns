class Solution {
public:
    int countPrimes(int n) {
if(n==1){return 0;}if(n==0){return 0;}
        vector<bool> arr(n,false);
        arr[0]=true;arr[1]=true;
        int j=0;
        int sum=0;
        for(int i=2;i<=n/2;i++){
            j=2*i;sum=i;
            while(j<n){arr[j]=true;j+=sum;}
        }
        int sol=0;
        for(bool c: arr){if(!c){sol++;}}
        //if(n>=2){sol++;}
        return sol;
    }
};
