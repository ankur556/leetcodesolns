class Solution {
public:
    void helper(vector<vector<char>>&a,int & cur,int  cur_tot,string & digits,vector<string> & sol,string&curv){
        if(cur_tot==digits.size()){if(curv.size()==digits.size()){sol.push_back(curv);}return;}
        else{
            for(int i=0;i<a[digits[cur_tot]-'2'].size();i++){
                curv.push_back(a[digits[cur_tot]-'2'][i]);
                helper(a,cur,cur_tot+1,digits,sol,curv);
                curv.pop_back();
            }
            return;
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> sol;
        int cur_tot=0;
        int cur=0;
        vector<vector<char>>a;
        vector<char>b;
        a.push_back(b);
        a[a.size()-1].push_back('a');
        a[a.size()-1].push_back('b');
        a[a.size()-1].push_back('c');
        a.push_back(b);
        a[a.size()-1].push_back('d');
        a[a.size()-1].push_back('e');
        a[a.size()-1].push_back('f');
        a.push_back(b);
        a[a.size()-1].push_back('g');
        a[a.size()-1].push_back('h');
        a[a.size()-1].push_back('i');
        a.push_back(b);
        a[a.size()-1].push_back('j');
        a[a.size()-1].push_back('k');
        a[a.size()-1].push_back('l');
        a.push_back(b);
        a[a.size()-1].push_back('m');
        a[a.size()-1].push_back('n');
        a[a.size()-1].push_back('o');
        a.push_back(b);
        a[a.size()-1].push_back('p');
        a[a.size()-1].push_back('q');
        a[a.size()-1].push_back('r');
        a[a.size()-1].push_back('s');
        a.push_back(b);
        a[a.size()-1].push_back('t');
        a[a.size()-1].push_back('u');
        a[a.size()-1].push_back('v');
        a.push_back(b);
        a[a.size()-1].push_back('w');
        a[a.size()-1].push_back('x');
        a[a.size()-1].push_back('y');
        a[a.size()-1].push_back('z');
        string t;
        helper(a,cur,cur_tot,digits,sol,t);
        return sol;
    }
};
