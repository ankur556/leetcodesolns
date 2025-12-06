class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> a;
        for(char c: magazine){
            a[c]++;
        }
        for(char c: ransomNote){
            a[c]--;
            if(a[c]<0){return false;}
        }
        return true;
    }
};
