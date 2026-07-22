class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /// new max -> no value of other elements
        // out of index
        //max-----min
        /// top <ele pop;
       deque<pair<int,int>> dq;
       for(int i=0;i<k-1;i++){
        while(!dq.empty()&&dq.front().second<nums[i]){
            dq.pop_front();
        }
        dq.push_front({i,nums[i]});
       }
       vector<int> sol;
       //sol.push_back(dq.back().second);
       for(int i=k-1;i<nums.size();i++){
        while(!dq.empty()&&dq.back().first<=i-k){dq.pop_back();}
         while(!dq.empty()&&dq.front().second<nums[i]){
            dq.pop_front();
        }
        dq.push_front({i,nums[i]});
        sol.push_back(dq.back().second);
       }
    return sol;
    }
};