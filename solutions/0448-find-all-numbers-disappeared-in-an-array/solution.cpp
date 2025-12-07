class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> a;
        for(int i=1;i<nums.size()+1;i++){a.push_back(i);}
        for(int i=0;i<nums.size();i++){
            a[nums[i]-1]=0;
        }
    vector<int>d;
    for(int i=0;i<a.size();i++){
        if(a[i]==0){continue;}
        else{d.push_back(a[i]);}
    }
    return d;
    }
};
