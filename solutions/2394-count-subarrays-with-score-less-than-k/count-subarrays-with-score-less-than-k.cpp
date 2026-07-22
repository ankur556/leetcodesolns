class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        vector<long long> sum;
        long long temp=0;
        for(int i: nums){
            sum.push_back(temp);
            temp+= i;
            //sum.push_back(temp);
        }
        //0 2 3 7 10 15
        //k= 10  3->7
        sum.push_back(temp);
        long long sol=0;
        int st=0;
        for(int i=0;i<sum.size();i++){
            while( st<=i  && (1LL*(i-st)*(sum[i]-sum[st])) >= k){
                st++;
            } 
            sol+=(i-st);
            //cout<<i<<" "<<st<<endl;
        }
        return sol;
    }
};