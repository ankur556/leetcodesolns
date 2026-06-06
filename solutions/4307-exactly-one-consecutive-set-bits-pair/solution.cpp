class Solution {
public:
    bool consecutiveSetBits(int n) {
        vector<int> a;
        while(n>0){
            a.push_back(n%2);
            n/=2;
        }
        int cont=0;
        for(int i=1;i<a.size();i++){
            if(a[i]==1&&a[i-1]==1){cont++;}
        }
        return cont==1;
    }
};
