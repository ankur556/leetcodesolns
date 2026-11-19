class Solution {
public:
    int minChanges(string s) {
        vector<int> help;
        int cur=1;char cur_char=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==cur_char){cur++;}
            else{
                help.push_back(cur);
                cur=1;
                cur_char=s[i];
            }
        }
        if(cur>0){help.push_back(cur);}
        int sol=0;
        for(int i=0;i<help.size()-1;i++){
            if(help[i] % 2 && help[i+1] % 2){
                sol++;help[i]++;help[i+1]++;
            }
            else if(help[i]%2){
                sol++;help[i]++;help[i+1]++;
            }
        }
        return sol;
    }
};