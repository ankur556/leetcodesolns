class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        int odds=0;
        int sol=0;
        for(int i=0;i<nums.size();i++){
            nums[i]%=2;
        }
         int j = 0;
        int count = 0, zeros = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            while (sum > goal && j < i) {
                sum -= nums[j];

                if (nums[j] != 0)
                    zeros = 0;

                j++;
            }

            while (nums[j] == 0 && j < i) {
                zeros++;
                j++;
            }

            if (sum == goal)
                count += (zeros + 1);
        }

        return count;
    }
};
