class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        // we can either put the beans to zero or we can put the beans to the standard amount
        // both cases we have to remove beans we cant add
        int n=beans.size();
        sort(beans.begin(),beans.end());
        vector<long long> sum;
        long long cur=0;
        for(int i: beans){cur+=i;sum.push_back(cur);}
        // sum till all possible index now we can evaluate value at each index in o(1)
        // sum till i-1 and sum till end -sum till i-1 -nums[i]*(endidx-i)
        /// 1 4 6 5 
        //if we turn all till 0 => 0 (none)
        // sum-min*n
        //sum[n-1]-n*nums[0]
        //if we turn all till 4(index 1 )=>0
        // sum[i-1]+sum[n-1]-sum[i]-(n-i)*
        long long acc=INT_MAX;
        for(int i=0;i<sum.size();i++){
            if(i==0){acc=sum[n-1]-(1LL*n*beans[i]);}
            else{
                long long cur=sum[i-1]+sum[n-1]-1LL*sum[i]-(1LL*(n-1-i)*beans[i]);
                acc=min(acc,cur);
            }
        }
        return acc;
    }
};