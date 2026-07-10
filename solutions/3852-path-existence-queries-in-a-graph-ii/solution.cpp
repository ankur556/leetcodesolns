
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
      vector<pair<int,int>> a;
      for(int i=0;i<n;i++){
        a.push_back({nums[i],i});
      }  
      sort(a.begin(),a.end());
      unordered_map<int,int> map;
      int cnt=0;
      for(auto t: a){
        map[t.second]=cnt;cnt++;
      }
      int cur=0;
      int LOG = 20; 
    vector<vector<int>> up(n, vector<int>(LOG, 0));
int right = 0;
for(int i = 0; i < n; i++) {
    while(right + 1 < n && a[right + 1].first - a[i].first <= maxDiff) {
        right++;
    }
    up[i][0] = right;
}
    for (int j = 1; j < LOG; j++) {
    for (int i = 0; i < n; i++) {
        up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }
    vector<int> ans;
for (auto& q : queries) {
    int start = map[q[0]];
    int target =map[q[1]];

    // If they are the exact same node, it takes 0 jumps
    if (start == target) {
        ans.push_back(0);
        continue;
    }

    // Always jump from left to right (smaller value to larger value)
    if (start > target) {
        swap(start, target);
    }

    int jumps = 0;
    
    // Jump as close as possible to the target without reaching/passing it
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[start][j] < target) {
            start = up[start][j];
            jumps += (1 << j); // 1 << j is the same as 2^j
        }
    }

    // After the loop, one more jump is required to either reach the target
    // or realize it is unreachable (disconnected)
    start = up[start][0];
    jumps++;

    // Did we reach or pass the target?
    if (start >= target) {
        ans.push_back(jumps);
    } else {
        ans.push_back(-1);
    }
}
return ans;

    }
};
