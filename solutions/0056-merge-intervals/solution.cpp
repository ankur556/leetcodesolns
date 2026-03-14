class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& sol) {
        sort(sol.begin(),sol.end());
        if(sol.size()<=1){return sol;}
        vector<vector<int>> a;
        int max3=sol[0][1];int min3=sol[0][0];
        bool inc=false;
        for(int i=0;i<sol.size();i++){
            if(max(max3,min3)>=min(sol[i][0],sol[i][1])){
                max3=max(max3,sol[i][1]);
                min3=min(min3,sol[i][0]);
                }
            else{
                a.push_back({min3,max3});
                min3=sol[i][0];
                max3=sol[i][1];
                
            }}
            a.push_back({min3,max3});
            return a;
    }
};
