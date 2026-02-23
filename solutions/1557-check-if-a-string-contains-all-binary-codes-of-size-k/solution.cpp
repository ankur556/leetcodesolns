class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //s.push_back('0');
     unordered_map<string,int>  b;
     if (s.length() < k) {
            return false;
        }
        int r=k;
        k = 1 << k;
     for(int i=0;i<s.size()-r+1;i++){
        if(b[(s.substr(i,r))]==0){b[(s.substr(i,r))]++;k--;}
     } 
     return k==0;
    }
};
