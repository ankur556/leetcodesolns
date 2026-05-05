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

ListNode* rotate(ListNode* l1) {
    // If list is empty or has only one element, no rotation
    if (l1 == nullptr || l1->next == nullptr) {
        return l1;
    }

    ListNode* temp1 = l1;
    ListNode* temp2 = l1->next;

    // Move until temp2 is the last node
    while (temp2->next != nullptr) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // Rotate: last node becomes new head
    temp2->next = l1;
    temp1->next = nullptr;

    return temp2;
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Find the length of the list
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }

        // Optimize rotations
        k %= len;
        if (k == 0) return head;

        // Perform k rotations
        for (int i = 0; i < k; i++) {
            head = rotate(head);
        }
        return head;
    }
};
