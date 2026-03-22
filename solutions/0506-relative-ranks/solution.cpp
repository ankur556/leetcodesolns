class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
       unordered_map<int,int> a;
       vector<int> helper=score;
       sort(helper.begin(),helper.end());
       for(int i=helper.size()-1;i>=0;i--){
        a[helper[i]]=helper.size()-i;
       } 
       for(int i=0;i<score.size();i++){
        score[i]=a[score[i]];
       }
       vector<string> sol;
       for(int i=0;i<score.size();i++){
        if(score[i]==1){sol.push_back("Gold Medal");}
        else if(score[i]==2){sol.push_back("Silver Medal");}
        else if(score[i]==3){sol.push_back("Bronze Medal");}
        else{string d;while(score[i]>0){d.push_back(score[i]%10+'0');score[i]=score[i]/10;}
        reverse(d.begin(),d.end());sol.push_back(d);}
       }
       return sol;
    }
};
