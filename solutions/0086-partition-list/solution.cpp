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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        vector<int> low;
        vector<int> high;
        int size=0;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<size;i++){
            if(temp->val<x){low.push_back(temp->val);temp=temp->next;}
            else{high.push_back(temp->val);temp=temp->next;}
        }
        temp=head;
        for(int i=0;i<low.size();i++){
            temp->val=low[i];temp=temp->next;
        }
        for(int i=0;i<high.size();i++){
            temp->val=high[i];temp=temp->next;
        }
        return head;
    }
};
