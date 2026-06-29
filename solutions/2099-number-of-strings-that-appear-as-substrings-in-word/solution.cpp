class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int> map;
        int n=word.size();
        for(int i=0;i<n;i++){
            string a;
            for(int j=i;j<n;j++){
                a.push_back(word[j]);
                map[a]++;
            }
        }
        int sol=0;
        for(int i=0;i<patterns.size();i++){if(map[patterns[i]]>0){sol++;}}
        return sol;
    }
};
