class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char,int> fs; 
        unordered_map<char,int> ft; 
        unordered_map<char,char> mp; 
        
        for(int i = 0; i < s.size(); i++){

            fs[s[i]]++;
            ft[t[i]]++;

            if(fs[s[i]] != ft[t[i]]){ return false; }
 
            if(mp.count(s[i])){
                if(mp[s[i]] != t[i]) return false;
            } else {
                mp[s[i]] = t[i];
            }
        }
        return true;
    }
};
