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
        ListNode* temp=head;
        int size=0;
        vector<int> odd;
        vector<int> even;
        while(temp!=nullptr){
            size++;temp=temp->next;
        }
        temp=head;
        for(int i=0;i<size;i++){
            if(i%2==1){even.push_back(temp->val);temp=temp->next;}
            else{odd.push_back(temp->val);temp=temp->next;}
        }
        temp=head;
        for(int i=0;i<odd.size();i++){
            temp->val=odd[i];
            temp=temp->next;
        }
        for(int i=0;i<even.size();i++){
            temp->val=even[i];
            temp=temp->next;
        }
        return head;
    }
};
