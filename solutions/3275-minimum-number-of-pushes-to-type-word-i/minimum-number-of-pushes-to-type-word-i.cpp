class Solution {
public:
    int minimumPushes(string word) {
        int cur=0;
        vector<int> f(26);
        for(char c: word){
            int i=c-'a';
            f[i]++;
        }
        sort(f.rbegin(),f.rend());
        int sol=0;
        for(int i=0;i<f.size();i++){
            if(i<8){sol+=f[i];}
            else if(i<16){sol+=(2*f[i]);}
            else if(i<24){sol+=(3*f[i]);}
            else{sol+=(4*f[i]);}
        }
        return sol;
    }
};