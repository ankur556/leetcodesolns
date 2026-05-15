class Solution {
public:
    int findMin(vector<int>& nums) {
       int l=0;
       int r=nums.size()-1;
       int mid=(l+r)/2;
       int min=nums[0];
       int sorted_till=0;
       //for(int i=1;i<nums.size();i++){
       // if(nums[i-1]<nums[i]){sorted_till++;}
       // else{break;} 
       //}
       if(nums.size()==1){return nums[0];}
       else if(nums.size()==2){if(nums[0]<nums[1]){return nums[0];}else{return nums[1];}}
       while(l<r){
        mid=(l+r)/2;
        if(nums[l]<min){min=nums[l];}
        if(nums[mid]<min){min=nums[mid];}
        if(nums[mid]<nums[nums.size()-1]){r=mid-1;}
        else{l=mid+1;}
       }
       if(nums[l]<min){min=nums[l];}
       return min;
   }
};
