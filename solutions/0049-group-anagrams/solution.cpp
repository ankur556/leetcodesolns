class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>> a;
        for(int i=0;i<strs.size();i++){a.push_back({strs[i],i});}
        for(int i=0;i<a.size();i++){sort(a[i].first.begin(),a[i].first.end());}
        sort(a.begin(),a.end());
        vector<vector<string>>sol;
        vector<string>b;
        sol.push_back(b);
        sol[0].push_back(strs[a[0].second]);
        for(int i=1;i<a.size();i++){if(a[i].first==a[i-1].first){sol[sol.size()-1].push_back(strs[a[i].second]);}
        else{vector<string>r;sol.push_back(r);sol[sol.size()-1].push_back(strs[a[i].second]);}}
        return sol;
    }
};
