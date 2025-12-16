class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=1e6;
        int sum;
        int mid;
        while(left<right){
            mid=(left+right)/2;sum=0;
            for(int a:nums){
                sum+=(a+mid-1)/mid;
            }
            if(sum>threshold){left=mid+1;}
            else{right =mid;}
        }
        return left;
    }
};
