class Solution {
public:
    void helper(vector<string>& sol,string &cur,int pushed,int rpushed,int n){
        if(pushed==n&&rpushed==n){sol.push_back(cur);return;}
        if(pushed<n){
            cur.push_back('(');
            helper(sol,cur,pushed+1,rpushed,n);
            cur.pop_back();
        }
        if(rpushed<pushed){
            cur.push_back(')');
            helper(sol,cur,pushed,rpushed+1,n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int pushed=0;
        int rpushed=0;
        string s;
        vector<string> sol;
        helper(sol,s,pushed,rpushed,n);
        return sol;
    }
};