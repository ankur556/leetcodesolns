class Solution {
public:
    bool isPowerOfThree(int n) {
        bool ans=false;
        if(n==0){return false;}
        else if(n==1){ans=false;return true;}
        else {for(int i=0;i<30;i++){
            if(n%3==0){
                n=n/3;
            }
            else if(n==1){ans=true;break;}
            else if(n%3==1||n%3==2){
                break;
            }
           
        }
        
        
        }
        return ans;
}
};
