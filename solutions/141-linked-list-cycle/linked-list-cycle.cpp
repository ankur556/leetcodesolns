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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> map;
        ListNode* node=head;
        while(node!=nullptr){
            map[node]++;
            if(map[node]>1){return true;}
            node=node->next;
        }
        return false;
    }
};