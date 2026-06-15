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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp!=nullptr){n++;temp=temp->next;}
        if(n<=1){return nullptr;}
        if(n==2){head->next=nullptr;return head;}
        n=(n-2)/2;
        temp=head;
        for(int i=0;i<n;i++){temp=temp->next;}
        temp->next=temp->next->next;
        return head;
    }
};
