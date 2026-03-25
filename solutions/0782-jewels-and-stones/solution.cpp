class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
    unordered_map<char,int>a;
    for(char c:jewels){a[c]++;}
    int sol=0;
    for(char c: stones){if(a[c]>0){sol++;}}
    return sol;
    }
};
