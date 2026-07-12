class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> b=arr;
        sort(b.begin(),b.end());
        unordered_map<int,int> cnt;
        int c=0;
        for(int i=0;i<arr.size();i++){
            if(cnt[b[i]]==0){c++;cnt[b[i]]=c;}
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=cnt[arr[i]];
        }
        return arr;
    }
};