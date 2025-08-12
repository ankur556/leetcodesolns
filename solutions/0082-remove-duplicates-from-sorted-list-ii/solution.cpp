class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head) {
            if (head->next && head->val == head->next->val) {
                int duplicateVal = head->val;
                while (head && head->val == duplicateVal) {
                    head = head->next; // skip all duplicates
                }
                prev->next = head; // link to non-duplicate
            } else {
                prev = prev->next;
                head = head->next;
            }
        }
        return dummy.next;
    }
};

