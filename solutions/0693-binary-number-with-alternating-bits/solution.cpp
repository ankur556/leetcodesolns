class Solution {
public:
    bool hasAlternatingBits(int n) {
        //if(n==1){return true;}
        //if(n==2){return true;}
        //if(n==3){return false;}
        //if(n==4){return true;}
        vector<int> helper;
        int k=n;
        while(k>0){helper.push_back(k%2);k=k/2;}
        bool sol=true;int ones=1;
        for(int i=0;i<helper.size()-1;i++){
            if(helper[i]==helper[i+1]){sol=false;break;}
        }
        return sol;
    }
};
