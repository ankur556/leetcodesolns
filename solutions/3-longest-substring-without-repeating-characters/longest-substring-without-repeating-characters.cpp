class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st=0;
        int sol=0;
        if(s.size()==0){return 0;}
        unordered_map<char,int> map;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
            while(map[s[i]]>1){
                map[s[st]]--;
                st++;
            }
            if(i-st+1>sol){sol=i-st+1;}
        }
        return sol;
    }
};