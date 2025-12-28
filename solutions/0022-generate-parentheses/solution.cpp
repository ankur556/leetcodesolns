class Solution {
public:
    void helper(vector<string> & sol,string curr,int open,int close,int n){
        if(close<open){helper(sol,curr+")",open,close+1,n);}
        if(open<n){open++;curr.push_back('(');helper(sol,curr,open,close,n);}
        if(open==n&&close==n){sol.push_back(curr);}
    }
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        vector<string> sol;
        string curr;
        helper(sol,curr,open,close,n);
        return sol;
    }
};
