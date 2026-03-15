class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        if(points.size()<=1){return points.size();}
        int sol=0;
        int curr=points[0][1];
        for(int i=0;i<points.size();i++){
            if(curr>=points[i][0]){if(points[i][1]<curr){curr=points[i][1];}}
            else{sol++;curr=points[i][1];}
        }
        return sol+1;
    }
};
