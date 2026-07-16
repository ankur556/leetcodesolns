class Solution {
public:
    bool isval(vector<int>& nums,int k,int val){//this fxn returns true at k=3 arr=1,4,4 and val=2 was fixed by adding the if codn at line 7
        int cnt=0;
        int cur=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>val){return false;}
            if(nums[i]+cur<=val){
                cur+=nums[i];
            }
            //else if(i==nums.size()-1){cnt++;}
            else{
                cnt++;
                cur=nums[i];
                //cout<<cur<<" "<<cnt<<endl;
            }
        }
        return cnt<k;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        for(int i: nums){sum+=i;}
        int r=sum+1;
        int l=0;
        int mid=l+(r-l)/2;
        while(l<r){
            mid=l+(r-l)/2;
            if(isval(nums,k,mid)){r=mid;}
            else{l=mid+1;}
            cout<<mid<<endl;
        }
        return l;
    }
};