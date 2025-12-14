class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookie=s.size();
        int boy=g.size();
        int ans=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(cookie>0&&boy>0){
            if(s[cookie-1]>=g[boy-1]){ans++;boy--;cookie--;}
            else if(g[boy-1]>s[cookie-1]){boy--;}
        }
        return ans;
    }
};
