class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> min(n);
        for(int i=0;i<n;i++){min[i]=i;}
        for(int i=1;i<nums.size();i++){
            if((nums[i]-nums[i-1])<=maxDiff){min[i]=min[i-1];}//cout<<i<<endl;}
        }
        vector<bool> sol;
        for(int i=0;i<queries.size();i++){
            if(queries[i][1]<queries[i][0]){swap(queries[i][0],queries[i][1]);}
            if(min[queries[i][1]]<=queries[i][0]){sol.push_back(true);}
            else{sol.push_back(false);}
        }
        return sol;
    }
};