class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> zeros;
        if(!nums.size()){return 0;}
        int cnt=0;
        for(int i: nums){
            cnt+=(1^i);
            zeros.push_back(cnt);
        }

    int st=0;
    int sol=0;
    cnt=0;
    for(int i=0;i<nums.size();i++){
        cout<<i<<endl;
        if(nums[i]==0){cnt++;}
        if(i+1>sol&&k!=0){sol=i+1;}
        if(k<=cnt){break;}
    }
    for(int i=0;i<nums.size();i++){
        while((zeros[i]-zeros[st])>k){st++;}
        if(i-st>sol){sol=i-st;}
        //cout<<i<<" "<<st<<endl;
    }
    if(zeros[zeros.size()-1]<=k){sol=zeros.size();}
    return sol;
    }
};