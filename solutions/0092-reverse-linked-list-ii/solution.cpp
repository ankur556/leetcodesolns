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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp=head;
        int a=left;
        vector<int> helper;
        while(a>1){a--;temp=temp->next;}
        for(int i=left;i<=right;i++){helper.push_back(temp->val);temp=temp->next;}
        temp=head;
        a=left;
        while(a>1){a--;temp=temp->next;}
        for(int i=helper.size()-1;i>=0;i--){temp->val=helper[i];temp=temp->next;}
        return head;
    }
};
