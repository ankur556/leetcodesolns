class Solution {
public:
    string largestOddNumber(string num) {
        int l=0;
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2){l=i;break;}
        }
        l++;
        if(l>1){return num.substr(0,l);}
        else{
            if((num[0]-'0')%2==0){return "";}
            else{return num.substr(0,l);}
        }
    }
};