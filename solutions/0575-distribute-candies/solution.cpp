class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_map<int,int> a;
        int can=0;
        for(int i: candyType){if(a[i]==0){a[i]++;can++;}else{a[i]++;}}
        return min(can,n/2);
    }
};
