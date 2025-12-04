class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     
        vector<int> a;
        for(ListNode* list : lists) { 
            ListNode* curr = list;
            while(curr != nullptr) {
                a.push_back(curr->val);
                curr = curr->next;
            }
        }

        sort(a.begin(), a.end());

        if (a.empty()) {
            return nullptr;
        }

        ListNode* dummyHead = new ListNode(0);

        ListNode* helper = dummyHead; 

        for(int val : a) {

            helper->next = new ListNode(val);

            helper = helper->next;
        }
 
        ListNode* ans = dummyHead->next;
        
        delete dummyHead;
        
        return ans; 
    }
};
