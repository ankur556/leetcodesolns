class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int st=0;
        int end=0;
        vector<pair<int,int>> a;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                st=i;end=st;
                while(i<s.size()&&s[i]=='1'){
                    end++;i++;
                }
                a.push_back({st,end-1});
            }
        }
        long long sum=0;
        for(int i=0;i<a.size();i++){
            st=a[i].first;
            end=a[i].second;
            long long cur_sum=0;
            int min_val=1e9;
            int start_idx=(st==0)?0:st-1;
            for(int j=start_idx;j<=end;j++){
                cur_sum+=nums[j];
                if(nums[j]<min_val){min_val=nums[j];}
            }
            if(st==0){sum+=cur_sum;}
            else{sum+=(cur_sum-min_val);}
        }
        return sum;
    }
};
