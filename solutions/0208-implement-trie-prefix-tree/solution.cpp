class TrieNode {
public:
    TrieNode *child[26];
    bool isword;
    TrieNode(){
        isword=false;
        for(auto & a:child){a=nullptr;}
    }};
    class Trie {
    public:
    TrieNode* root;
    TrieNode* root_1;
    Trie() {
        root=new TrieNode();root_1=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*p=root;
        for(auto & i: word){
            if(!p->child[i-'a']){p->child[i-'a']=new TrieNode();}
            p=p->child[i-'a'];
        }
        p->isword=true;
         p=root_1;
        for(auto & i: word){
            p->isword=true;
            if(!p->child[i-'a']){p->child[i-'a']=new TrieNode();}
            p=p->child[i-'a'];
        }
        p->isword=true;
    }
    
    bool search(string word) {
        TrieNode *p=root;
        for(auto & a: word){
            if(!p->child[a-'a']){return false;}
            p=p->child[a-'a'];
        }
        return p->isword;

    }
    
    bool startsWith(string prefix) {
                TrieNode *p=root_1;
        for(auto & a: prefix){
            if(!p->child[a-'a']){return false;}
            p=p->child[a-'a'];
        }
        return p->isword;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
