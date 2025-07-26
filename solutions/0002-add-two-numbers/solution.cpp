class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head to simplify handling the start of the new list
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        // Loop as long as there is a node in l1, l2, or there's a carry left over
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the values, using 0 if the list has ended
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum for the current digit
            int sum = val1 + val2 + carry;

            // Update the carry for the next digit
            carry = sum / 10;

            // Create the new node with the correct digit (sum % 10)
            current->next = new ListNode(sum % 10);

            // Move all pointers forward
            current = current->next;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        // The result list starts after the dummy head
        ListNode* result = dummyHead->next;
        delete dummyHead; // Clean up the dummy node
        return result;
    }
};
