class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1]!=9){digits[digits.size()-1]++;return digits;}
        else if(digits.size()==1){return {1,0};}
        else{
            bool found= false;
            for(int i=0;i<digits.size();i++){
                if(digits[digits.size()-i-1]!=9){digits[digits.size()-i-1]++;
                        for(int j=digits.size()-i;j<digits.size();j++){
            digits[j]=0;
        }
                return digits;found=true;break;}
            }
        digits[0]=1;digits.push_back(9);
        for(int i=1;i<digits.size();i++){
            digits[i]=0;
        }
        return digits;
        }
return digits;
    }
};
