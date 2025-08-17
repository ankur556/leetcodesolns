class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int index=0;
    for(int i=0;i<s.size();i++){
        if(s[s.size()-1-i]==' '){continue;}
        else{index=i;break;}
    }
    for(int i=index;i<s.size();i++){
        if(s[s.size()-i-1]==' '){return ans;}
        else{ans++;}
    }
        return ans;
    }
};
