class Solution {
public:
    bool sorted(string s){
        for(int i=0;i<s.size()-1;i++){
            if(s[i+1]<s[i]){return false;}
        }
        return true;
    }
    int minOperations(string s) {
        if(sorted(s)){return 0;}
        if(s.size()<=2){return -1;}
        else{  
            int min=1e5;
            int max=0;
            for(char c : s){
                if((int)(c)<min){min=c;}
                if((int)(c)>max){max=c;}
            }
            int max_cnt=0;
            int min_cnt=0;
            for(char c : s){if(c==max){max_cnt++;}if(c==min){min_cnt++;}}
            if(s[0]==min||s[s.size()-1]==max){return 1;}
            else if(s[s.size()-1]==min&&s[0]==max&&max_cnt==1&&min_cnt==1){return 3;}
            else{return 2;}
        }
    }
};