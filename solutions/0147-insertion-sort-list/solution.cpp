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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> acc;
        ListNode* temp=head;
        while(temp!=nullptr){acc.push_back(temp->val);temp=temp->next;}
        sort(acc.begin(),acc.end());
        temp=head;
        int i=0;
         while(temp!=nullptr){temp->val=acc[i];i++;temp=temp->next;}
         return head;
    }
};
