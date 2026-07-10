/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){return nullptr;}
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=nullptr){
                //cout<<temp->val;
                pq.push(temp->val);
                temp=temp->next;
                //cout<<pq.top()<<endl;
            }
        }
        //vector<ListNode*> sol;
        //if(sol.size()==0){return nullptr;}
        if(pq.empty()){return nullptr;}
        ListNode* n=new   ListNode(pq.top());
        pq.pop();
        ListNode* ne=n;
        while(!pq.empty()){            
           // cout<<"no issue wt loop?"<<endl;
            ListNode* nq=new  ListNode(pq.top());
            pq.pop();
            ne->next=nq;
            ne=nq;
            cout<<pq.top()<<endl;
        }
        return n;
    }
};
