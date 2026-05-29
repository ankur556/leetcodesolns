class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int max=intervals[0][1];
        int min=intervals[0][0];
        vector<vector<int>> sol;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<=std::max(max,min)){
                max=std::max(intervals[i][1],max);
                min=std::min(intervals[i][0],min);
            }
            else{
                vector<int> a;
                sol.push_back(a);
                sol[sol.size()-1].push_back(min);
                sol[sol.size()-1].push_back(max);
                min=intervals[i][0];
                max=intervals[i][1];
            }
        }
        vector<int> a;
                sol.push_back(a);
                sol[sol.size()-1].push_back(min);
                sol[sol.size()-1].push_back(max);
                return sol;
    }
};
