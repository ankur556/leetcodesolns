class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        for(int i=0;i<nums.size();i++){
            nums[i]=(nums[i]%2);
        }
        int sol=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum>0){
                    double r=(double)(j-i-sum+1)/(sum);
                    if(r<=(double(a))/double(b)){sol++;}
                }
            }
        }
        return sol;
    }
};