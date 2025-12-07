class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int prev=1;
        vector<string> a;
        for(int i=0;i<target.size();i++){
            for(int j=prev;j<target[i];j++){
                a.push_back("Push");
                a.push_back("Pop");
                prev=target[i];
            }
            prev++;
            a.push_back("Push");
        }
        return a;
    }
};
