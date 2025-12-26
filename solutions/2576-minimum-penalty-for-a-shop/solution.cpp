class Solution {
public:
    int bestClosingTime(string customers) {
        int post_yay=0;
        int post_nay=0;
        int pre_yay=0;
        int pre_nay=0;
        for(char c: customers){
            if(c=='Y'){post_yay++;}
            else{post_nay++;}
        }
        int sol=-1;
        int max=post_yay;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y'){post_yay--;pre_yay++;}
            else{post_nay--;post_yay++;}
            if(post_yay+pre_nay<max){sol=i;max=post_yay+pre_nay;}

        }
        return sol+1;

    }
};
