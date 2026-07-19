class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> a(n+1);
        for(int i:banned){if(i<a.size()){a[i]++;}}
        int sum=0;int st=1;int cnt=0;
        while(sum<maxSum&&st<=n){
            if(a[st]==0){
                sum+=st;
                //st++;
                if(sum<=maxSum){cnt++;}
            }
            st++;
        }
        return cnt;
    }
};