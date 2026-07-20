class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> numdiff;
        for(int i=0;i<reward1.size();i++){numdiff.push_back(reward1[i]-reward2[i]);
        }//element pushed correctly
        sort(numdiff.begin(),numdiff.end());
        int sum=0;
        for(int i: reward2){sum+=i;}
        //cout<<sum<<endl;
        // correct sum till here issue after this
        //k=1 nums size==1 start from
        //loop isnt running
        for(int i=numdiff.size()-k;i<numdiff.size();i++){
            sum+=numdiff[i];
        }
        return sum;
    }
};