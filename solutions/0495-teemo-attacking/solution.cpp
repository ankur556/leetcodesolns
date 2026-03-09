class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int duration) {
        int sol=0;
        for(int i=1;i<t.size();i++){
            if(t[i]-t[i-1]>duration){sol+=duration;}
            else{sol+=t[i]-t[i-1];}
        }
        sol+=duration;
        return sol;
    }
};
