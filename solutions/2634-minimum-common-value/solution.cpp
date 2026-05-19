class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> a;
        int min=0;
        for(int i: nums1){a[i]++;}
        for(int i: nums2){if(a[i]!=0){return i;}}
        return -1;
    }
};
