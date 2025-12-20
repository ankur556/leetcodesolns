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
        int size=1;
        while(temp->next!=nullptr){size++;temp=temp->next;}

        if(size>3){
        temp=head;
        int muv=size/2;
        for(int i=0;i<muv-1;i++){temp=temp->next;}
        temp->next=temp->next->next;
        return head;
        }
        else if(size==3){
            temp=head;
            temp->next=temp->next->next;
            return head;
        }
        else if(size==2){
            temp=head;
            temp->next=nullptr;
            return head;
        }
        else{
            temp=nullptr;
            return temp;
        }
    }
};
