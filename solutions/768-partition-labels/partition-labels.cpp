class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> st(26,-1);
        vector<int> end(26,-1);

        for(int i=0;i<s.size();i++){
            if(st[s[i]-'a']==-1){
                st[s[i]-'a']=i;
            }
            end[s[i]-'a']=i;
        }

        vector<vector<int>> intervals;

        for(int i=0;i<26;i++){
            if(st[i]!=-1){
                intervals.push_back({st[i],end[i]});
            }
        }

        sort(intervals.begin(),intervals.end());

        int sta=intervals[0][0];
        int ends=intervals[0][1];

        vector<vector<int>> acc;

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= ends){
                ends=max(intervals[i][1],ends);
            }
            else{
                acc.push_back({sta,ends});
                sta=intervals[i][0];
                ends=intervals[i][1];
            }
        }

        // Don't forget the last interval
        acc.push_back({sta,ends});

        vector<int> sol;
        int prev=-1;

        for(auto x:acc){
            sol.push_back(x[1]-prev);
            prev=x[1];
        }

        return sol;
    }
};