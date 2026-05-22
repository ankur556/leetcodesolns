class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a=0;
        int max=0;
        unordered_map<char,int> last;
        int cnt=0;
        int st=0;
        for(char c: s){
            cnt++;
            a=cnt;
            st=std::max(last[c],st);
            last[c]=cnt;
            if(max<a-st){max=a-st;}
        }
        return max;
    }
};
