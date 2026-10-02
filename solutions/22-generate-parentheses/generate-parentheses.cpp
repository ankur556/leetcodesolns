class Solution {
public:
    int n;
    void helper(vector<string> & sol,int  cur_op,int  cur,string & s){
        if(cur==n&&cur_op==n){sol.push_back(s);}
        if(cur<n){
            s.push_back('(');
            helper(sol,cur_op,cur+1,s);
            s.pop_back();
        }
        if(cur_op<cur){
            s.push_back(')');
            helper(sol,cur_op+1,cur,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int b) {
        n=b;
        vector<string> a;
        int cur_op=0;
        int cur=0;
        string s;
        helper(a,cur_op,cur,s);
        return a;
    }
};