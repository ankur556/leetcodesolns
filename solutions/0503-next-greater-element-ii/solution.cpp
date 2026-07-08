class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n=nums.size();
       int max=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]>nums[max]){max=i;}
       }
       cout<<max<<endl;
       stack<int> s;
       s.push(nums[max]);
       nums[max]=-1;
       for(int i=max-1;i>=0;i--){
        while(!s.empty()&&s.top()<=nums[i]){s.pop();}
        if(s.empty()){s.push(nums[i]);nums[i]=-1;cout<<"np"<<endl;}
        else{int k=nums[i];
        nums[i]=s.top();
        s.push(k);}
       }
       for(int i=nums.size()-1;i>=max+1;i--){
         while(!s.empty()&&s.top()<=nums[i]){s.pop();}
        if(s.empty()){s.push(nums[i]);nums[i]=-1;}
        else{int k=nums[i];
        nums[i]=s.top();
        s.push(k);}
       }
       return nums;
    }
};
