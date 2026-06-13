class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        //vector<int> helper;
        string sol;
        int cur=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                cur+=(weights[words[i][j]-'a']);
            }
            sol.push_back('z'-cur%26);
            cur=0;
        }
    return sol;
    }
};
