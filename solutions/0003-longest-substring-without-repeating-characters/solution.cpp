class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0;
        int start=0;
        vector<int> last(256, -1);
        for(int end=0;end<s.size();end++){
            char c=s[end];
            if(last[c]>=start){
                start=last[c]+1;
            }
            last[c]=end;
            max_len=max(max_len,end-start+1);
        }
        return max_len;
    }
};
