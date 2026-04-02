class Solution {
public:
    vector<string> summaryRanges(vector<int>& n) {
        // 1. Safety check for empty input
        if (n.empty()) return {}; 

        vector<long long> nums;
        for(int i : n) { nums.push_back(i); }
        
        vector<pair<long long, long long>> a;
        
        // 2. Changed to long long so 'end++' doesn't overflow at INT_MAX
        long long init = 0; 
        long long end = 0;  
        
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                init = nums[i];
                end = nums[i];
                if(i == nums.size() - 1) { a.push_back({init, end}); }
            } 
            else {
                if(nums[i] == nums[i-1] + 1) {
                    end++;
                    if(i == nums.size() - 1) { a.push_back({init, end}); }
                } 
                else {
                    a.push_back({init, end});
                    init = nums[i];
                    end = nums[i];
                    if(i == nums.size() - 1) { a.push_back({init, end}); }
                }
            }
        }  
        
        vector<string> s(a.size());
        
        // 3. Replaced manual ASCII character math with to_string()
        for(int i = 0; i < a.size(); i++) {
            if(a[i].first == a[i].second) { 
                s[i] = to_string(a[i].first);
            } 
            else {
                s[i] = to_string(a[i].first) + "->" + to_string(a[i].second);
            }
        }
        
        return s;
    }
};
