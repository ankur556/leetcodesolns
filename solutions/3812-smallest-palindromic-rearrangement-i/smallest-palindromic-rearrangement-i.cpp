class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26,0);
        for(char c: s){
            int i=c-'a';
            cnt[i]++;
        }
        int oddidx=-1;
        int oddval=0;
        for(int i=0;i<cnt.size();i++){
            if(cnt[i]%2){oddidx=i;cnt[i]--;}
        }
        string sol;
        for(int i=0;i<cnt.size();i++){
            int k=cnt[i]/2;
            for(int j=0;j<k;j++){
                sol.push_back('a'+i);
            }
        }
        if(oddidx!=-1){sol.push_back('a'+oddidx);}
        for(int i=cnt.size()-1;i>=0;i--){
            int k=cnt[i]/2;
            for(int j=0;j<k;j++){
                sol.push_back('a'+i);
            }
        }
        return sol;
    }
};