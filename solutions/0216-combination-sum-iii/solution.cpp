class Solution {
public:
    void helper(vector<vector<int>> & sol,vector<int> & cur,int ptr,int sum,int pushed,int k,int n){
        if(sum>n){return;}
        else if(ptr>=10){return;}
        else if(pushed==k){return;}
        else if(pushed>k){return;}
        else{
            for(int i=ptr;i<10;i++){
                cur.push_back(i);
                helper(sol,cur,i+1,sum+i,pushed+1,k,n);
                if(pushed+1==k&&sum+i==n){sol.push_back(cur);}
                //cout<<sum<<endl;
                cur.pop_back();
                //helper(sol,cur,i+1,sum,pushed,k,n);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> sol;
        vector<int> cur;
        int curptr=1;
        int cursum=0;int pushed=0;
        helper(sol,cur,curptr,cursum,pushed,k,n);
        return sol;
    }
};
