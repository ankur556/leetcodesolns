class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> helper;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){zero++;}
            helper.push_back(zero);
        }
        if(helper[helper.size()-1]<=k){return helper.size();}
        int st=0;
        int end=k;
        int max=0;
        unordered_map<int,int> last;
        for(int i=0;i<nums.size();i++){
        if(last[helper[i]]>0){}
        else{last[helper[i]]=i+1;}
        if(helper[i]<k+1){if(i+1>max){max=i+1;}}
        else if(last[helper[i]-k]>0&&i-last[helper[i]-k]+1>max){max=i-last[helper[i]-k]+1;}
        }
        return max;
    }
};
