/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head!=nullptr&&head->next!=nullptr&&head->next->next!=nullptr){
        ListNode* slow=head->next;
        ListNode* fast=head->next->next;
        
        int n=0;
        while(fast->next!=nullptr&&fast->next->next!=nullptr&&fast!=slow){slow=slow->next;fast=fast->next->next;}
        if(fast->next==nullptr||fast->next->next==nullptr){return nullptr;}
        else{
        slow=head;
        while(slow!=fast){slow=slow->next;fast=fast->next;}
        return fast;
        }
        
    }else{return nullptr;}
    }
};
