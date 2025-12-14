class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> a;
        for(char c:s){a[c]++;}
        vector <pair<int,char>> b;
        unordered_set<char> c;
        for(int i=0;i<s.size();i++){
            if(c.contains(s[i])){continue;}
            else{c.insert(s[i]);b.push_back({a[s[i]],s[i]});}
        }
        string sol;
        sort(b.begin(),b.end());
        for(int j=0;j<b.size();j++){
            for(int i=0;i<b[b.size()-j-1].first;i++){
                sol.push_back(b[b.size()-j-1].second);
            }
        }
        return sol;
    }
};
