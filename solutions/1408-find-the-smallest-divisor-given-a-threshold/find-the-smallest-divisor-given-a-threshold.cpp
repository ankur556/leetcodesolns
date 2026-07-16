class Solution {
public: 
    bool isval(vector<int>&nums,int mid,int thres){
        int temp=0;
        for(int i:nums){if(i%mid){temp+=(i/mid+1);}else{temp+=(i/mid);}}
        return temp<=thres;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        /// sum of (all elements by k)<threshold
        // so max val of threshold -> sum/k +1 as we have to find the min
        int r=1e9;
        int l=1;
        int mid=l+(r-l)/2;
        while(l<r){
            mid=l+(r-l)/2;
            if(isval(nums,mid,threshold)){r=mid;}
            else{l=mid+1;}
        }
        return l;
    }
};