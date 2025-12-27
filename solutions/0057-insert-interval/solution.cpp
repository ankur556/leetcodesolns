class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> sol;
        int i = 0;
       
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            sol.push_back(intervals[i]);
            i++;
        }
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        sol.push_back(newInterval); 
        while (i < intervals.size()) {
            sol.push_back(intervals[i]);
            i++;
        }

        return sol;
    }
};
