class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> a;
        for(int i=0;i<nums.size();i++){a.push_back(nums[i]);}
        for(int i=0;i<nums.size();i++){a.push_back(nums[i]);}
        stack<int> b;
        vector<int> sol(2*nums.size());
        for(int i=a.size()-1;i>=0;i--){
            while(!b.empty()&&a[b.top()]<=a[i]){b.pop();}
            if(b.empty()){sol[i]=-1;b.push(i);}
            else{sol[i]=a[b.top()];b.push(i);}
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=sol[i];
        }
        return nums;
    }
};
