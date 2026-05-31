class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& as) {
        long long m=mass;
        sort(as.begin(),as.end());
        for(int &i:as){
            if(i>m){return false;}
            else{m+=i;}
        }
        return true;
    }
};
