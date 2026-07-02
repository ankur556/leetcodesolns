class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> map;
        for(int i: deck){map[i]++;}
        int min_till=0;
        for(int i: deck){min_till=gcd(map[i],min_till);}
       return min_till>1;
    }
};