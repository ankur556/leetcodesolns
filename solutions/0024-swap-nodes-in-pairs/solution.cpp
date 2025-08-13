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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head; // 0 or 1 node → nothing to swap

        ListNode* newHead = head->next;  // After first swap, 2nd node becomes head
        ListNode* prevTail = nullptr;    // Tail of the already processed part
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* first = curr;
            ListNode* second = curr->next;
            ListNode* nextPair = second->next;

            // Swap
            second->next = first;
            first->next = nextPair;

            // Connect previous swapped pair
            if (prevTail) {
                prevTail->next = second;
            }

            // Move prevTail to end of swapped pair
            prevTail = first;
            curr = nextPair;
        }

        return newHead;
    }
};

