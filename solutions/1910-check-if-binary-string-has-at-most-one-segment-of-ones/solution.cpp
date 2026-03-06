class Solution {
public:
    bool checkOnesSegment(string s) {
        int ones=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'&&s[i+1]=='1'){ones++;}
            else if(s[i]=='1'&&s[i+1]=='0'){ones++;}
        }
        return !(ones>1);
    }
};
