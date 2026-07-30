class Solution {
public:
    bool ispal(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
    void helper(vector<vector<string>>& sol, vector<string>& to_push,
                string& cur, string s, int idx) {
        if (idx == s.size()) {
            //cur.push_back(s[idx]);
            if (ispal(cur)&&cur.size()>0) {
                to_push.push_back(cur);
                sol.push_back(to_push);
                to_push.pop_back();
                return;
            } else {
               // cur.pop_back();
                //to_push.pop_back();
                return;
            }
        } else {    
                cur.push_back(s[idx]);
                helper(sol, to_push, cur, s, idx + 1);
                if (ispal(cur)){
                to_push.push_back(cur);
                string sn;
                helper(sol, to_push, sn , s, idx +1 );
                to_push.pop_back();
                }
                cur.pop_back();
            } 
        }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> sol;
        int idx = 0;
        vector<string> to_push;
        string cur;
        helper(sol, to_push, cur, s, idx);
        return sol;
    }
};