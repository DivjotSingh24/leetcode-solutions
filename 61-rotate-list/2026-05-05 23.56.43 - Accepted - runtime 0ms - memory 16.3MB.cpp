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
int length(ListNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}
ListNode*  rotateOnce(ListNode* head){
    if(head==nullptr || head->next ==nullptr)return head;
    ListNode* prev=nullptr;
    ListNode*curr=head;
    while(curr->next){
        prev=curr;
        curr=curr->next;
    }
    prev->next=nullptr;
    curr->next=head;
    return curr;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==nullptr || head->next==nullptr || k==0) return head;
        int n=length(head);
        k=k%n;
        if (k==0) return head;
        for (int i=0;i<k;i++){
            head=rotateOnce(head);
        }
        return head;
    }
};