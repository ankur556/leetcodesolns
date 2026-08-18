class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k==1){
            int max=-1;
            unordered_map<int,int> cnt;
            for(int i : nums){cnt[i]++;}
            for(int i : nums){if(cnt[i]==1&&i>max){max=i;}}
            return max;
        }
        else if(nums.size()==k){
            int max=nums[0];
            for(int i : nums){if(i>max){max=i;}}
            return max;
        }
        else{
            int stcnt=0;
            int endcnt=0;
            for(int i : nums){
                if(i==nums[0]){stcnt++;}
                if(i==nums[nums.size()-1]){endcnt++;}
            }
            if(stcnt==1&&endcnt==1){return std::max(nums[0],nums[nums.size()-1]);}
            else if(stcnt==1){return nums[0];}
            else if(endcnt==1){return nums[nums.size()-1];}
            else{return -1;}
        }
    }
};