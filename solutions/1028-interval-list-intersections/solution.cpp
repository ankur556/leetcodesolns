class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int fpt=0;
        int spt=0;
        vector<vector<int>> sol;
        int i=0;
        bool ab=true;
        while(fpt<firstList.size()&&spt<secondList.size()){
            if(max(firstList[fpt][0],secondList[spt][0])>min(firstList[fpt][1],secondList[spt][1])){}
            else{ vector<int> a;sol.push_back(a);sol[i].push_back(max(firstList[fpt][0],secondList[spt][0]));
            sol[i].push_back(min(firstList[fpt][1],secondList[spt][1]));i++;}
            if(firstList[fpt][1]<=secondList[spt][0]){fpt++;}
            else if(firstList[fpt][0]>=secondList[spt][1]){spt++;}
            else if(firstList[fpt][1]>secondList[spt][1]){spt++;}
            else{fpt++;}
        }
        return sol;
    }
};
