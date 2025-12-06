class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        ListNode* b = head; 
        while(b != nullptr){
            a.push_back(b->val);
            b = b->next;
        }
        int size = a.size(); 
        for(int i = 0; i < size / 2; i++){
            if(a[i] != a[size - 1 - i]){ 
                return false;
            }
        }
        return true;
    }
};
