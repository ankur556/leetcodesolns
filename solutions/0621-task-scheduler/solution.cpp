class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // map<int,int> m;
        int total = tasks.size();
        vector<pair<int,int>> m(26,{-1,-1});
        // for(int i=0; i<)
        for(int i=0; i<26; i++){
            m[i]={0,i};
        }

        for(char c : tasks){
            m[c-'A'].first++;
        }
        sort(m.begin(), m.end(), greater<pair<int,int>>());

        vector<int> wait(26,-1);
        int t=0;
        while(total>0){
            for(int i=0; i<26; i++){
                if(m[i].first>0 && t>wait[m[i].second]){
                    m[i].first--;
                    wait[m[i].second]=t+n;
                    total--;
                    break;
                }
            }
            t++;
             sort(m.begin(), m.end(), greater<pair<int,int>>());
        }
        return t;
    }
};
