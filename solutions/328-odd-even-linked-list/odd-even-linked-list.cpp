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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr){return head;}
        if(head->next==nullptr){return head;}
        vector<ListNode*> odd;
        vector<ListNode*> even;
        ListNode* temp=head;
        int n=1;
        while(temp!=nullptr){if(n%2){odd.push_back(temp);}else{even.push_back(temp);}n++;temp=temp->next;}
        ListNode* sol=head;
        ListNode* h=sol;
        for(int i=1;i<odd.size();i++){h->next=odd[i];h=h->next;}
        for(int i=0;i<even.size();i++){h->next=even[i];h=h->next;}
        h->next=nullptr;
        return sol;
    }
};