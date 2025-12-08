class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int no_of_9s=0;
        for(int i=0;i<digits.size();i++){
            if(digits[i]==9){no_of_9s++;}
        }
        if(no_of_9s==digits.size()){
            vector<int> ans;
            ans.push_back(1);
            for(int i=0;i<digits.size();i++){
                ans.push_back(0);
            }
            return ans;
        }
        else{
            for(int i=0;i<digits.size();i++){
                if(digits[digits.size()-i-1]==9){digits[digits.size()-i-1]=0;}
                else{digits[digits.size()-i-1]=digits[digits.size()-i-1]+1;break;}
            }
            return digits;
        }
    }
};
