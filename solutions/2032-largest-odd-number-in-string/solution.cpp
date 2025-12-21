class Solution {
public:
    string largestOddNumber(string num) {
        int end_idx=0;
        for(int i=num.size()-1;i>=0;i--){if(num[i]=='1'||num[i]=='3'||num[i]=='5'||num[i]=='7'||num[i]=='9'){end_idx=i+1;break;}}
        string ans;
        for(int i=0;i<end_idx;i++){ans.push_back(num[i]);}
        return ans;
        
    }
};
