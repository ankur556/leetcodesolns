class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int st=target[0]-start[0];
        int end=target[1]-start[1];
        if((st+end)%2==0){return true;}
        else{return false;}
    }
};