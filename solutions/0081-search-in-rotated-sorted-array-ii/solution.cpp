class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int lower = 0;
        int higher = n - 1;
        int min = *min_element(nums.begin(), nums.end());
        int shift = 0;
        bool flag = false;
        if (higher == 0) {
            if (nums[0] == target) return true;
            else return false;
        } else {
            for (int i = 0; i <= higher; i++) {
                if (nums[i] == min) { shift = i;break; }
            }
            if (target < nums[higher]) {
                lower = shift; higher = n - 1;
            } else if (target > nums[shift]) {
                lower = 0; higher = shift - 1;
            } else if (target == nums[shift] || target == nums[higher]) {
                return true;
            }
            while (lower <= higher) {
                int mid = (lower + higher) / 2;
                if (nums[mid] == target || nums[lower] == target || nums[higher] == target) {
                    flag = true;
                    break;
                }
                if (target > nums[mid]) {
                    lower = mid + 1;
                } else if (target < nums[mid]) {
                    higher = mid - 1;
                }
                else if (nums[mid] == nums[lower] && nums[mid] == nums[higher]) {
                    lower++;
                    higher--;
                }
            }
        }
        if(flag==false){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){flag=true;break;}
        }}
        return flag;
    }
};

