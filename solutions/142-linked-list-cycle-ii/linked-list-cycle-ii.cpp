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
        unordered_map<ListNode*,int> map;
        while(head!=nullptr&&map[head]!=1){map[head]++;head=head->next;}
        if(head==nullptr){return nullptr;}
        else{return head;}
    }
};