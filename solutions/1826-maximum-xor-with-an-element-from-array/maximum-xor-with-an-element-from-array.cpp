struct Node{
    public:
    Node* Links[2];
    Node(){
        Links[0]=Links[1]=nullptr;
    }
    bool containsKey(int key){
        return Links[key]!=nullptr;
    }
    Node* get(int bit){
        return Links[bit];
    }
    void set(int bit,Node* node){
            Links[bit]=node;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* cur = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!cur->containsKey(bit)){
                cur->set(bit,new Node());
            }
            cur=cur->get(bit);
        }
    }
    int getMaxXor(int a){
        int sol=0;
        Node* cur=root;
        for(int i=31;i>=0;i--){
            int bit=(a>>i)&1;
            if(!cur->containsKey(1-bit)){
                cur=cur->get(bit);
            }
            else{
                sol|=(1<<i);
                cur=cur->get(1-bit);  
            }
        }
        return sol;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int,pair<int,int>>> quieries_modified;
        for(int i=0;i<queries.size();i++){
            quieries_modified.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(quieries_modified.begin(), quieries_modified.end());
        sort(nums.begin(),nums.end());
        Trie trie;
        int st=0;
        vector<pair<int,int>> sols;
        for(auto a: quieries_modified){
            while(st<nums.size()&&nums[st]<=a.first){trie.insert(nums[st]);st++;}
            if(st==0){sols.push_back({-1,a.second.second});}
            else{int max=trie.getMaxXor(a.second.first);
            sols.push_back({max,a.second.second});}
        }
        vector<int> sol(queries.size());
        for(int i=0;i<sols.size();i++){
            sol[sols[i].second]=sols[i].first;
        }
        return sol;
    }
};