class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target){return 0;}
            else return -1;
        }
        else if(nums.size()==2){
            if(nums[0]==target){return 0;
            }
            else if(nums[1]==target){
                return 1;
            }
            else{return -1;}
        }
        else if(nums.size()==3){
            if(nums[0]==target){return 0;
            }
            else if(nums[1]==target){
                return 1;
            }
            else if(nums[2]==target){
                return 2;
            }
            else{return -1;}
        }
        int smoll=0;
        int high=nums.size();
        int mid=0;
        for(int i=1;i<nums.size()*2;i++){
            mid=smoll+(high-smoll)/2;
            if(target>nums[mid]){
                smoll=mid;
            }
            else if(target<nums[mid]){
                high=mid;
            }
            else{return mid;}
        }
        return -1;
    }
};
