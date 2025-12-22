class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
       stack<int> neg;
       stack<int> pos;
       bool r=false;
       for(int i=nums.size()-1;i>=0;i--){
        r=false;
        if(nums[i]<0){
            neg.push(i);
        }
        else if(nums[i]>0){
            while(!neg.empty()&&abs(nums[neg.top()])<=nums[i]){
                if(nums[i]==abs(nums[neg.top()])){neg.pop();r=true;break;}
                neg.pop();}
            if(r){continue;}
            else if(neg.empty()){pos.push(i);}
            else{continue;}
        }
        else{continue;}
       }
       vector<int> sol;
       while(!pos.empty()||!neg.empty()){if(neg.empty()){sol.push_back(pos.top());pos.pop();}
       else if(pos.empty()){sol.push_back(neg.top());neg.pop();}
       else if(pos.top()>neg.top()){sol.push_back(neg.top());neg.pop();}
       else if(pos.top()<neg.top()){sol.push_back(pos.top());pos.pop();}
      else{sol.push_back(neg.top());neg.pop();}}
       for(int i=0;i<sol.size();i++){sol[i]=nums[sol[i]];}
       return sol;
    }
};
