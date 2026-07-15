class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0){return intervals;}
        sort(intervals.begin(),intervals.end());
        int start_interval=intervals[0][0];int end_interval=intervals[0][1];
        vector<vector<int>> sol;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<=end_interval){
                start_interval=min(intervals[i][0],start_interval);
                end_interval=max(intervals[i][1],end_interval);
            }
            else{
                sol.push_back({start_interval,end_interval});
                start_interval=intervals[i][0];end_interval=intervals[i][1];

            }
        }
        sol.push_back({start_interval,end_interval});
        return sol;
    }
};
