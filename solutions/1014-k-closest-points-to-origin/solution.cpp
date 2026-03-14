class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<long long>> b;

        for(int i=0;i<points.size();i++){
            vector<long long> a;
            a.push_back(points[i][1]*points[i][1]+points[i][0]*points[i][0]);
            a.push_back(i);
            b.push_back(a);
        }
        sort(b.begin(),b.end());
        vector<vector<int>> sol;
        for(int i=k-1;i>=0;i--){sol.push_back(points[b[i][1]]);}
        return sol;
        
        //long long max=0;
        //int idx=0;
        //for(int i=0;i<a.size();i++){if(a[i]>max){max=a[i];}}
        //vector<int> g;
        //for(int i=0;i<a.size();i++){if(a[i]==max){g.push_back(i);}}

    }
    
};
