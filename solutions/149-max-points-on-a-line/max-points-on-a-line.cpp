class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==0){return 0;}
        int sol=0;
        sort(points.begin(),points.end());
        for(int i=0;i<points.size();i++){
            unordered_map<double,int> map;
            for(int j=i+1;j<points.size();j++){
                int x1=points[i][0];
                int x2=points[j][0];
                int y1=points[i][1];
                int y2=points[j][1];
                double slope=(double)(y2-y1)/(x2-x1);
                if(x1==x2){map[301]++;sol=max(sol,map[301]);}
                else{map[slope]++;sol=max(sol,map[slope]);}
            }
        }
        return sol+1;
    }
};