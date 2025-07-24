class Solution {
public:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
ListNode *head1 = headA;
ListNode *head2 = headB;
int ele1 = 0;
int ele2 = 0;
ListNode *temp = headA;
while(temp != nullptr){
temp = temp->next;
ele1++;
}
temp = headB;
while(temp != nullptr){
temp = temp->next;
ele2++;
}
head1 = headA;
head2 = headB;
for(int i = 0; i < ele1; i++) {
ListNode* current2 = head2;
for(int j = 0; j < ele2; j++) {
if(head1 == current2) {
return head1;
}
current2 = current2->next;
}
head1 = head1->next;
}
return nullptr;
}
};

