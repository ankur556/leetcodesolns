class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gptr=g.size()-1;int sptr=s.size()-1;int sol=0;
        sort(g.begin(),g.end());sort(s.begin(),s.end());
        while(gptr>=0&&sptr>=0){
            if(g[gptr]<=s[sptr]){sol++;gptr--;sptr--;}
            else{gptr--;}
        }
        return sol;
    }
};
