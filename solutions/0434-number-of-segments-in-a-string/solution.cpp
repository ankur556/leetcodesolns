class Solution {
public:
    int countSegments(string s) {
        int sol=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){}
            else{
                sol++;
                while(i<s.size()&&s[i]!=' '){i++;}
            }
        }
    return sol;
    }

};
