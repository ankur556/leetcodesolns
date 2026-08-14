class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> f(26,0);
        vector<int> n(26,0);
        int sol=0;
        for(int i=0;i<s.size();i++){
            f=n;
            for(int j=i;j<s.size();j++){
                f[s[j]-'a']++;
                if(f[s[j]-'a']<=2){sol=std::max(sol,j-i+1);}
                else{break;}
            }
        }
        return sol;
    }
};