ListNode* mergelist(ListNode* list1, ListNode* list2) {
    ListNode dummy; // temporary dummy node
    ListNode* tail = &dummy; // tail points to end of merged list
    dummy.next = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Connect the rest
    if (list1 != nullptr) tail->next = list1;
    else tail->next = list2;

    return dummy.next;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return mergelist(list1, list2);
    }
};

