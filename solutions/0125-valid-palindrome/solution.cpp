class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) { 
                ans.push_back(tolower(s[i])); 
            }}
    for(int i=0;i<ans.size();i++){
        if(ans[i]==ans[ans.size()-1-i]){continue;}
        else{return false;}
    }
    return true;
    }
};
