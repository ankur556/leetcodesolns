class Solution {
public:
    bool isself(int a){
        vector<int> help;
        //bool sol=true;
        int temp=a;
        while(temp>0){if(temp%10==0){return false;}else{help.push_back(temp%10);temp=temp/10;}}
        for(int i=0;i<help.size();i++){if(a%help[i]==0){continue;}else{return false;}}
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
      vector<int> sol;
      for(int i=left;i<right+1;i++){if(isself(i)){sol.push_back(i);}}  
      return sol;
    }
};
