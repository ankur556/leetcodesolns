class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<n;i++){
            odd.push_back(nums[i]);
        }
        for(int i=n;i<2*n;i++){
            even.push_back(nums[i]);
        }

        for(int i=0;i<2*n;i++){
            if(i%2==0){nums[i]=odd[i/2];}
            else{nums[i]=even[i/2];}
        }
        return nums;
    }
};
