class Solution {
public:
    string reverseWords(string s) {
        vector<string> help;
        string g;
        help.push_back(g);
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){help.push_back(g);}
            else{help[help.size()-1].push_back(s[i]);}
        }
        string sol;
        int cor=0;
        int k=0;
        for(int i=0;i<help.size();i++){if(help[i].size()!=0){k=i;}}
        reverse(help.begin(),help.end());
        for(int i=0;i<help.size();i++){
            cor=0;
            for(int j=0;j<help[i].size();j++){
                if(help[i][j]!=' '){sol.push_back(help[i][j]);cor++;}
            }
            if(cor!=0){sol.push_back(' ');}
        }
        while(sol[sol.size()-1]==' '){sol.pop_back();}
        return sol;
    }
};
