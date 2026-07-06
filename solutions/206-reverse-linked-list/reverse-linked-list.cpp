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
    ListNode* recursive(ListNode* node){
        if(node==nullptr){return node;}
        vector<ListNode*> a;
        ListNode* temp=node;
        while(temp!=nullptr){
            a.push_back(temp);
            temp=temp->next;
        }
        temp=a[a.size()-1];
        node=temp;
        for(int i=a.size()-2;i>=0;i--){
            temp->next=a[i];temp=temp->next;
        }
        temp->next=nullptr;
        return node;
    }
    ListNode* iti(ListNode*node){
        ListNode* temp=node;
        int n=0;
        while(temp!=nullptr){n++;temp=temp->next;}
        ListNode * og=node;
        for(int i=n-1;i>=(n)/2;i--){
            temp=node;
            for(int j=0;j<i;j++){
                temp=temp->next;
            }
            swap(og->val,temp->val);
            og=og->next;
        }
        return node;
    }
    ListNode* reverseList(ListNode* head) {
        //the recusive methord works
       // return recursive(head);
       //iti methord
       return iti(head);
    }
};