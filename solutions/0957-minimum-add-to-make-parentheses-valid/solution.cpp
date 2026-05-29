class Solution {
public:
    int minAddToMakeValid(string s) {
        int d=0;
        int h=0;
        for(char c: s){
            if(c=='('){d++;}
            else{
                if(d>0){d--;}
                else{h++;}
            }
            
        }
        return d+h;
    }
};
