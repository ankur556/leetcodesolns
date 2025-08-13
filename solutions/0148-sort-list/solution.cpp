class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; // Base case

        // 1. Split list into two halves
        ListNode* mid = getMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr; // Cut the list

        // 2. Sort each half
        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

        // 3. Merge sorted halves
        return merge(leftSorted, rightSorted);
    }

private:
    // Find middle using slow/fast pointers
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

