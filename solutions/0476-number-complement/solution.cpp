class Solution {
public:
    int findComplement(int num) {
        vector<int> helper;
        while(num>0){helper.push_back(num%2);num/=2;}
        int sol=0;
        for(int i=helper.size()-1;i>=0;i--){sol=sol*2;sol+=(1-helper[i]);}
        return sol;
    }
};
