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
    void helper(ListNode* a,int k){
        vector<int> b;
        ListNode * c=a;
        for(int i=0;i<k;i++){
            b.push_back(c->val);
            c=c->next;
        }
    for(int i=0;i<k/2;i++){
        swap(b[i],b[k-i-1]);
    }
    c=a;
    for(int i=0;i<k;i++){
        c->val=b[i];
        c=c->next;
    }

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1){return head;}
        else{
            int size=0;
            ListNode* temp=head;
            while(temp!=nullptr){size++;temp=temp->next;}
            int illi=size/k;
            vector<int> a;
            for(int i=0;i<illi;i++){
                temp=head;
                for(int j=0;j<i*k;j++){
                    temp=temp->next;
                }
                helper(temp,k);
            }
            return head;
    }
}};
