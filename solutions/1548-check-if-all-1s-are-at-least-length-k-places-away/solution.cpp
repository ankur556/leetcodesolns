#include <algorithm>
class Solution {
public:
    bool kLengthApart(vector<int>& a, int k) {
        for(int i=0;i<a.size();i++){
            if(a[i]==1){
                for(int j=i+1;j<(min(i+k+1,(int)a.size()));j++){
                    if(a[j]==1){return false;}
                }if(i+k<a.size()){i=i+k;}
                }
                else{continue;}
            }
    return true;    }
    
};
