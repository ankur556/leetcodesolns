class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> a;
        for(char c: s){a[c]++;}
        int sol=0;
        bool od=false;
        for(char c: s){if(a[c]!=0){if(a[c]%2==1){od=true;}sol+=(a[c]/2*2);a[c]=0;}}
        if(od){return sol+1;}
        else{return sol;}
    }
};
