class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){return false;}
        vector<int> a;
        while(x>0){
            a.push_back(x%10);x=x/10;
        }
        for(int i=0;i<a.size()/2;i++){if(a[i]==a[a.size()-1-i]){continue;}else{return false;}}
        return true;
    }
};
