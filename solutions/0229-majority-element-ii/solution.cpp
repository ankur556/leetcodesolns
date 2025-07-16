class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int first = 0, second = 1; 
        int fre1 = 0, fre2 = 0;
        vector<int> a;

        for(int i = 0; i < n; i++) {
            if(nums[i] == first) {
                fre1++;
            } else if(nums[i] == second) {
                fre2++;
            } else if(fre1 == 0) {
                first = nums[i];
                fre1 = 1;
            } else if(fre2 == 0) {
                second = nums[i];
                fre2 = 1;
            } else {
                fre1--;
                fre2--;
            }
        }

        fre1 = fre2 = 0;
        for(int num : nums) {
            if(num == first) fre1++;
            else if(num == second) fre2++;
        }
        if(fre1 > n/3) a.push_back(first);
        if(fre2 > n/3) a.push_back(second);

        return a;
    }
};

