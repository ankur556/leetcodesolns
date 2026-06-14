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
    int pairSum(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        vector<int> helper;
        while(temp!=nullptr){helper.push_back(temp->val);n++;temp=temp->next;}
        int sol=1;
        for(int i=0;i<helper.size();i++){sol=max(sol,helper[i]+helper[helper.size()-1-i]);}
        return sol;
    }
};
