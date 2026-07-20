class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> numdiff;
        for(int i=0;i<reward1.size();i++){numdiff.push_back(reward1[i]-reward2[i]);
        }//element pushed correctly
        sort(numdiff.begin(),numdiff.end());
        int sum=0;
        for(int i: reward2){sum+=i;}
        for(int i=numdiff.size()-k;i<numdiff.size();i++){
            sum+=numdiff[i];
        }
        return sum;
    }
};