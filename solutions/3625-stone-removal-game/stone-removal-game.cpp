class Solution {
public:
    bool canAliceWin(int n) {
      int st=0;
      for(int i=0;i<=10;i++){
        if(n>=10-i){n-=(10-i);}
        else{
            if(i%2){return true;}
            else{return false;}
        }
      }  
      return true;
    }
};