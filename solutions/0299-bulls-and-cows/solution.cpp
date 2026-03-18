class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> sc_cnt;
        for(char c: secret){sc_cnt[c]++;}
        int bulls=0;int cows=0;
        for(int i=0;i<guess.size();i++){if(guess[i]==secret[i]){bulls++;sc_cnt[guess[i]]--;guess[i]='a';}}
        for(int i=0;i<guess.size();i++){if(sc_cnt[guess[i]]!=0){cows++;sc_cnt[guess[i]]--;}}
        string sol;
        string bull;
        string cow;
        if(bulls>0){
        while(bulls>0){
        bull.push_back('0'+bulls%10);bulls=bulls/10;}
        for(int i=bull.size()-1;i>=0;i--){sol.push_back(bull[i]);}}
        else{sol.push_back('0');}
        sol.push_back('A');
        if(cows>0){
        while(cows>0){
        cow.push_back('0'+cows%10);cows=cows/10;}
        for(int i=cow.size()-1;i>=0;i--){sol.push_back(cow[i]);}}
        else{sol.push_back('0');}
        sol.push_back('B');
        return sol;
    }
};
