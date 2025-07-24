class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;

        // Count the number of nodes
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        int mid = cnt / 2;
        temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        return temp;
    }
};

