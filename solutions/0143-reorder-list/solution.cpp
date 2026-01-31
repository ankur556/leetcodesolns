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
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        int size=0;
        while(temp!=nullptr){size++;temp=temp->next;}
        vector<int> first;vector<int> last;
        temp=head;
        for(int i=0;i<size;i++){if(i<((size+1)/2)){first.push_back(temp->val);}else{last.push_back(temp->val);}temp=temp->next;}
        for(int i=0;i<last.size()/2;i++){swap(last[i],last[last.size()-1-i]);}
        temp=head;
        for(int i=0;i<first.size()+last.size();i++){if(i%2==0){temp->val=first[i/2];}else{temp->val=last[i/2];}temp=temp->next;}
        
    }
};
