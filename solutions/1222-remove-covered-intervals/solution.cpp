class Solution {
public:
    static bool sortfxn(const vector<int> & a,const vector<int> & b){
        if(b[0]>a[0]){return true;}
        else if(b[0]==a[0]){return a[1]>b[1];}
        else{return false;}
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),sortfxn);
        if(intervals.size()==0){return 0;}
        else{
            int st=intervals[0][0];
            int end=intervals[0][1];
            int sol=1;
            for(int i=1;i<intervals.size();i++){
                if(intervals[i][1]>end&&st==intervals[i][0]){end=intervals[i][1];}
                else if(intervals[i][1]>end){sol++;end=intervals[i][1];}
                else{}
            }
            return sol;
        }
    }
};
