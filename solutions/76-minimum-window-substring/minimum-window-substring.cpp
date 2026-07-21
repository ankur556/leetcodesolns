class Solution {
public:
    bool satisfied(unordered_map<char, int>& windowMap, unordered_map<char, int>& targetMap) {
    for (auto const& [ch, count] : targetMap) {
        if (windowMap[ch] < count) {
            return false;
        }
    }
    return true;
}
    string minWindow(string s, string t) {
        unordered_map<char,int> map;
        for(char c: t){map[c]++;}
        unordered_map<char,int> mapi;
        for(char c:s){mapi[c]++;}
        for(int i=0;i<256;i++){
            if(map[i]>mapi[i]){return "";}
        }
        unordered_map<char,int> newmap;
        int st=0;
        int opst=0;int opend=1e5;
        for(int i=0;i<s.size();i++){
            newmap[s[i]]++;
            while(satisfied(newmap, map)) {
        if(i - st < opend - opst) {
            opend = i;
            opst = st;
        }
        newmap[s[st]]--;
        st++;
    }
        }
        string solution;
        if (opend == 1e5) return "";
        for(int i=opst;i<=opend;i++){solution.push_back(s[i]);}
        return solution;
    }
};