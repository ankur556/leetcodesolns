class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());sort(s.begin(),s.end());
        int pg=g.size()-1;int ps=s.size()-1;
        int cnt=0;
        while(pg>=0&&ps>=0){
            if(g[pg]>s[ps]){pg--;}
            else{ps--;pg--;cnt++;}
        }
        return cnt;
    }
};
