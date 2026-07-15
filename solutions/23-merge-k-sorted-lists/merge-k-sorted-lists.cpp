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
        priority_queue<int,vector<int>,greater<int>> pq;
        ListNode* st;
        for(int i=0;i<lists.size();i++){
            st=lists[i];
            while(st!=nullptr){/*cout<<st->val<<endl;*/pq.push(st->val);st=st->next;}
        }
        if(pq.empty()){return nullptr;}
        ListNode* solution=new ListNode(pq.top());
        ListNode* temp=solution;
        pq.pop();
        while(!pq.empty()){
            cout<<pq.top()<<endl;
            ListNode* a=new ListNode(pq.top());
            pq.pop();
            temp->next=a;
            temp=temp->next;
        }
        return solution;
    }
};