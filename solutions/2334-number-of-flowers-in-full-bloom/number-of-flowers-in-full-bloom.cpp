class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> bl;
        vector<int> fd;
        vector<int> sol;
        for(int i=0;i<flowers.size();i++){
            bl.push_back(flowers[i][0]);
            fd.push_back(flowers[i][1]+1);
        }
        sort(bl.begin(),bl.end());sort(fd.begin(),fd.end());
        for(int i=0;i<people.size();i++){
            int stp=upper_bound(bl.begin(),bl.end(),people[i])-bl.begin();
            int edp=upper_bound(fd.begin(),fd.end(),people[i])-fd.begin();
            if(stp-edp<0){sol.push_back(0);}
            else{sol.push_back(stp-edp);}
        }
        return sol;
    }
};