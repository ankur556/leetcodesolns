class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0&&n==1){return 1;}
        unordered_map<int,int> trusted;
        unordered_map<int,int> trusting;
        for(int i=0;i<trust.size();i++){trusted[trust[i][1]]++;trusting[trust[i][0]]++;}
        for(int i=0;i<n+1;i++){if(trusted[i]==n-1&&trusting[i]==0){return i;}}
        return -1;
    }
};