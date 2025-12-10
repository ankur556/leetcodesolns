class Solution {
public:
    int countPermutations(vector<int>& c) {
        long long big=1000000007;
        for(int i=1;i<c.size();i++){
            if(c[i]<=c[0]){return 0;}
        }
        long long ans=1;
        for(int i=0;i<c.size();i++){
            if(c[i]>c[0]){ans=ans*i%big;}
        }
        return (int)ans;
        
       
    }
};
