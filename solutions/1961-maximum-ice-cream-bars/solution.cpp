class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sol=0;
        for(int i: costs){if(i<=coins){sol++;coins-=i;}else{break;}}
        return sol;
    }
};
