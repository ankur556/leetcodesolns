class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> a;
        for(char c: s){a[c]++;}
        int count=0;
        for(char c: s){if(a[c]==1){return count;}count++;}
        return -1;
    }
};
