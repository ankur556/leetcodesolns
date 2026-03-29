class Solution {
public:
vector<int> a;
int sum;
    Solution(vector<int>& w) {
        a=w;
       sum=0;
        for(int i=0;i<a.size();i++){sum+=a[i];a[i]=sum;}
    }
    
    int pickIndex() {
       int target = rand() % sum + 1;
        auto it= lower_bound(a.begin(),a.end(),target);
        return distance(a.begin(),it);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
