class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> dp(startTime.size());
        vector<vector<int>> st_end_pro;
        for(int i=0;i<startTime.size();i++){
            st_end_pro.push_back({endTime[i],startTime[i],profit[i]});
        }
        vector<int> ends;
        sort(st_end_pro.begin(),st_end_pro.end());
        for(auto a: st_end_pro){ends.push_back(a[0]);}
        dp[0]=st_end_pro[0][2];
        for(int i=1;i<st_end_pro.size();i++){
            int st=upper_bound(ends.begin(),ends.end(),st_end_pro[i][1])-ends.begin()-1;
            if(st>=0)dp[i]=max({dp[i-1],st_end_pro[i][2]+dp[st]});
            else{dp[i]=max(dp[i-1],st_end_pro[i][2]);}
        }
        return dp[dp.size()-1];
    }
};