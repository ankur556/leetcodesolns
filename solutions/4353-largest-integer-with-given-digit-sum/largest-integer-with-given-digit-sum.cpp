class Solution {
public:
    int largestInteger(int n, int s) {
        string sol;
        if(s>n*9){return -1;}
      for(int i=0;i<n;i++){
        if(s==0){sol.push_back('0');}
        else if(s>=9){sol.push_back('9');s-=9;}
        else{sol.push_back('0'+s);s=0;}
      }  
      return stoi(sol);
    }
};