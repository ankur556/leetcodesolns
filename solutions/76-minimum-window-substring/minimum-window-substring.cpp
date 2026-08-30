class Solution {
public:
    bool satisfied(vector<int>& windowMap,vector<int>& targetMap) {
        for(int i=0;i<256;i++){
            if(windowMap[i]<targetMap[i]){return false;}
        }
    return true;
}
    string minWindow(string s, string t) {
        vector<int> map(256);
        for(char c: t){map[c]++;}
        vector<int> mapi(256);
        for(char c:s){mapi[c]++;}
        for(int i=0;i<256;i++){
            if(map[i]>mapi[i]){return "";}
        }
        vector<int> newmap(256);
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