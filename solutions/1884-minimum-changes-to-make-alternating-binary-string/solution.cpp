class Solution {
public:
    int minOperations(string s) {
        int first0=0;
        int first1=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0&&s[i]=='1'){first1++;}
            else if(i%2==1&&s[i]=='0'){first1++;}
            else if(i%2==1&&s[i]=='1'){first0++;}
            else if(i%2==0&&s[i]=='0'){first0++;}
        }
        return min(first1,first0);
    }
};
