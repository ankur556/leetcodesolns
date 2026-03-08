class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int,int> m;
        int help=0;
        for(string n: nums){
            help=0;
            for(char c: n){
                help=help*2;
                if(c=='1'){help++;}
            }
        m[help]++;    
        }
        int hi=0;
        for(int i=0;i<nums.size()+1;i++){if(m[i]==0){hi=i;break;}}
        string sol;
        while(hi>0){sol.push_back(hi%2+'0');hi=hi/2;}
        while(sol.size()<nums[0].size()){sol.push_back('0');}
        for(int i=0;i<sol.size()/2;i++){swap(sol[i],sol[sol.size()-1-i]);}
        return sol;
    }
};
