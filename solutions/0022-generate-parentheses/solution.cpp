class Solution {
public:
    void rec(int n, int rem, vector<string>&ans,string & s){
        if(n==0 && rem==0){
            ans.push_back(s);
            return ;
        }
        if(n>0){
            s+='(';
            rec(n-1,rem+1, ans,s);
            s.pop_back();
        }
        if(rem>0){
            s+=')';;
            rec(n,rem-1,ans,s);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        rec(n,0,ans,s);
        return ans;
    }
};
