class Solution {
public:
    bool checkRecord(string s) {
        bool sol=true;
        int abs=0;
        int con_lat=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){con_lat++;}
            else if(s[i]=='A'){con_lat=0;abs++;}
            else{con_lat=0;}
            if(con_lat==3||abs>1){return false;}
        }
        return true;
    }
};
