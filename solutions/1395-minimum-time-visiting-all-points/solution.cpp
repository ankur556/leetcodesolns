class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sol=0;
        if(points.size()==0){return 0;}
        int curr_x=0;int curr_y=0;
        int trav_x=0;
        int trav_y=0;
        for(int i=0;i<points.size();i++){
            trav_x=abs(points[i][0]-curr_x);
            trav_y=abs(points[i][1]-curr_y);
            sol+=max(trav_x,trav_y);
            curr_x=points[i][0];
            curr_y=points[i][1];
        }
        return sol-max(abs(points[0][0]),abs(points[0][1]));
    }
};
