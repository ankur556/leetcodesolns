class Solution {
public:
    string reverseWords(string s) {

        s = ' ' + s + ' ';
        
        vector<int> a;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                a.push_back(i);
            }
        }
        
        string ans;

        for(int i = a.size() - 2; i >= 0; i--) {

            if (a[i+1] - a[i] > 1) {
                

                if (!ans.empty()) {
                    ans.push_back(' ');
                }

                for(int j = a[i] + 1; j < a[i+1]; j++) {
                    ans.push_back(s[j]);
                }
            }
        }  
        return ans;
    }
};
