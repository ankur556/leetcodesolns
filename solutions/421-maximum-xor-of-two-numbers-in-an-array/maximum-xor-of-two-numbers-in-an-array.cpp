class Node{
    public:
    Node* links[2];
    Node(){
    links[0]=links[1]=nullptr;
    }
    Node* get(int bit){
        return links[bit];
    }
    bool exists(int bit){
        return links[bit]!=nullptr;
    }
    void set(int bit){
        links[bit]=new Node();
        return;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(int a){
        Node* cur=root;
        for(int i=31;i>=0;i--){
            int bit=(a>>i)&1;
            if(cur->exists(bit)){
                cur=cur->get(bit);
            }
            else{
            cur->set(bit);
            cur=cur->get(bit);
            }
        }
    }
    int getMaxXor(int n){
        Node* cur=root;
        int sol=0;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(cur->exists(1-bit)){
                sol|=(1<<i);
                cur=cur->get(1-bit);
            }
            else{
                cur=cur->get(bit);
            }
        }
        return sol;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i: nums){trie.insert(i);}
        int sol=0;
        for(int i: nums){if(trie.getMaxXor(i)>sol){sol=trie.getMaxXor(i);}}
        return sol;
    }
};