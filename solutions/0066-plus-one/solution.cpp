class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int no_of_9s=0;
        vector<int> sol;
        for(int i=0;i<digits.size();i++){if(digits[i]==9){no_of_9s++;}}
        if(no_of_9s==digits.size()){
            sol.push_back(1);
            for(int i=0;i<digits.size();i++){
                sol.push_back(0);
            }
            return sol;
        
        }
        else{
            int a=digits.size()-1;
            while(digits[a]==9){digits[a]=0;a--;}
            digits[a]++;
            return digits;
        }
    }
};
