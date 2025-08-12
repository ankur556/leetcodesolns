class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* prev = head;
        ListNode* cur  = head->next;

        while (cur) {
            if (prev->val == cur->val) {
                // remove cur
                prev->next = cur->next;
                cur = prev->next;
                // (optional) delete the removed node if you want to free memory:
                // delete temp;
            } else {
                prev = cur;
                cur  = cur->next;
            }
        }
        return head;
    }
};

