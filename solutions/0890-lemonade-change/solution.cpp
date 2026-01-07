class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int no_of_5s=0;
        int no_of_10s=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){no_of_5s++;}
            else if(bills[i]==10){no_of_10s++;no_of_5s--;}
            else{
                if(no_of_10s==0){no_of_5s-=3;}
                else{no_of_5s--;no_of_10s--;}
            }
            if(no_of_5s<0||no_of_10s<0){return false;}
        }
        return true;
    }
};
