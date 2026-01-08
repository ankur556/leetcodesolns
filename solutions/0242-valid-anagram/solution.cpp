class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map1;unordered_map<char,int> map2;
        for(char i: s){map1[i]++;}
        for(char i: t){map2[i]++;}
        if(s.size()!=t.size()){return false;}
        for(int i=0;i<s.size();i++){if(map1[s[i]]!=map2[s[i]]){return false;}}
        return true;
    }
};
