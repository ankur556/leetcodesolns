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
    ListNode* sortList(ListNode* head) {
        vector<int> helper;
        ListNode* a=head;
        while(head!=nullptr){
            helper.push_back(head->val);
            head=head->next;
        }
        head=a;
        sort(helper.begin(),helper.end());
        for(int i=0;i<helper.size();i++){
            head->val=helper[i];
            head=head->next;
        }
        head=a;
        return head;
    }
};
