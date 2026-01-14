class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol;
        sol.push_back(0);
        if(n==0){return sol;}
        int i=1;int k=1;
        k=k*2;
        while(i<k&&i<n+1){sol.push_back(sol[i/2]+i%2);i++;if(i==k){k=k*2;}}
        return sol;
    }
};
