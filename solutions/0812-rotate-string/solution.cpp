class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size()){return false;}
        int n=s.size();
        for(int i=0;i<n;i++){s.push_back(s[i]);}
        bool sol=false;
        for(int i=0;i<n;i++){
            sol=true;
            for(int j=i;j<i+n;j++){
                if(s[j]!=goal[j-i]){sol=false;break;}
            }
            if(sol==true){return sol;}
        }
        return sol;
    }
};
