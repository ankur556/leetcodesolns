class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long energy=(brightness+2)/3;
        if (energy==0||intervals.empty()){return 0;}
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        long long tot=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end){
                end=max(intervals[i][1],end);
            }
            else{
                tot+=(end-start+1);
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        tot+=(end-start+1);
        return tot*energy;
    }
};
