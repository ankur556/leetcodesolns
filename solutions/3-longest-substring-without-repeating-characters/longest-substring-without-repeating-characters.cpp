class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st=0;
        vector<int> map(256);
        int sol=0;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
            while(map[s[i]]>1){map[s[st]]--;st++;}
            sol=std::max(sol,i-st+1);
        }
        return sol;
    }
};