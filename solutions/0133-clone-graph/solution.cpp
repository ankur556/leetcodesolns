/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){return nullptr;}
        Node* a=new Node(node->val);
        Node* temp=a;
        queue<pair<Node*,Node*>> nodepairs;
        nodepairs.push({temp,node});
        unordered_map<Node*,Node*> vis;
        while(!nodepairs.empty()){
            Node* first=nodepairs.front().first;
            Node* second=nodepairs.front().second;
            nodepairs.pop();
                vis[second]=first;
                vis[first]=second;
                for(int i=0;i<second->neighbors.size();i++){
                if(vis[second->neighbors[i]]==nullptr){
                Node* n=new Node (second->neighbors[i]->val);
                first->neighbors.push_back(n);
                vis[first->neighbors[i]]=second->neighbors[i];
                vis[second->neighbors[i]]=first->neighbors[i];
                nodepairs.push({first->neighbors[i],second->neighbors[i]});
                }
                   else{first->neighbors.push_back(vis[second->neighbors[i]]);}
                }
        }
        return a;
    }
};
