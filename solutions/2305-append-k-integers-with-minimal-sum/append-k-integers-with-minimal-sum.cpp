class Solution {
public:
   /* long long minimalKSum(vector<int>& nums, int k) {
        vector<int> hash(nums.size()+k+1);
        for(int i:nums){if(i<hash.size()){hash[i]++;}}
        long long sol=0;
        int curp=0;
        for(int i=1;i<hash.size();i++){
            if(hash[i]==0){sol+=i;curp++;if(curp==k){return sol;}}
        }
        //cout<<"(!) shoudnt get here"<<endl;
        return sol;
    }*/
    //inefficent approch :TLE o(k) wont work lets move to n log n which should:
    long long minimalKSum(vector<int>& n, int k) {
        long long sum=1000;
        unordered_map<int,int> vis;
        vector<int> nums;
        for(int i:n){if(vis[i]==0){vis[i]++;nums.push_back(i);}}
        sort(nums.begin(),nums.end());
        int end=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>k){end=i;break;}
            else{k++;sum-=nums[i];}
        }
        sum+=(1LL*(1LL*k*(1LL*(k+1)))/2);
        //for(int i=0;i<end;i++){sum-=nums[i];}
        return sum-1000;
    }
};