class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        for(char c : s){map1[c]++;}
        for(char c : t){map2[c]++;}
        for(char c: t){if(map1[c]!=map2[c]){return c;}}
        return t[t.size()-1];
    }
};
