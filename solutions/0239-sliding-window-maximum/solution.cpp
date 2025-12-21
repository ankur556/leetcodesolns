class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> a;
        vector<int> sol;
        int max=nums[0];
        for(int i=0;i<k;i++){
            if(nums[i]>max){max=nums[i];}
            while(!a.empty()&&nums[i]>nums[a.back()]){a.pop_back();}
            a.push_back(i);
        }
        sol.push_back(max);
        for(int i=k;i<nums.size();i++){
            if (!a.empty() && a.front() == i - k) {
                a.pop_front();
            }
            while(!a.empty()&&nums[i]>nums[a.back()]){a.pop_back();}
            a.push_back(i);
            sol.push_back(nums[a.front()]);
        }
        return sol;
    }
};
