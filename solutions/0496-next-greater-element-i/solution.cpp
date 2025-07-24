class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> posns;  

        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (nums1[i] == nums2[j]) {
                    posns.push_back(j);
                    break;  
                }
            }
        }

        int max_size = size1;
        vector<int> ans;

        for (int i = 0; i < max_size; i++) {
            bool found = false;
            for (int j = posns[i] + 1; j < size2; j++) {
                if (nums1[i] < nums2[j]) {
                    ans.push_back(nums2[j]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

