class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<string> b;
        for(auto c: words){b.push_back(c);}
        for(auto c: words){b.push_back(c);}
         for(auto c: words){b.push_back(c);}
         startIndex+=words.size();
        int sol=1e9;
        //bool s=false;
        for(int i=0;i<b.size();i++){
            if(b[i]==target){if(abs(i-startIndex)<sol){sol=abs(i-startIndex);}}
        }
        if(sol==1e9){return -1;}
        return sol;
    }
};
