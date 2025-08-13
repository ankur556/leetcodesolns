
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a = nums1;
        a.insert(a.end(), nums2.begin(), nums2.end());
        
        if (a.empty()) return 0.0;

        sort(a.begin(), a.end());

        
        if (a.size() % 2 == 0) {
            return (a[a.size()/2] + a[a.size()/2 - 1]) / 2.0;
        } else {
            return a[a.size()/2];
        }
    }
};

