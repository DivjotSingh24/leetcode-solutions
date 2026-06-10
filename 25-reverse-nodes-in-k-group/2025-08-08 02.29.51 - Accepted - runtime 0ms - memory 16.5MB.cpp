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
ListNode* getkthnode(ListNode* temp,int k){
     k-=1;
     while(k>0 && temp){
        temp=temp->next;
        k--;
     }
     return temp;

}
ListNode* reverse(ListNode* head){
    ListNode* temp=head;
    ListNode* prev=nullptr;
    while(temp!=nullptr){
        ListNode* nexxt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nexxt;
        
    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* kthnode=getkthnode(temp,k);
            if(kthnode==nullptr){
                if (prev!=nullptr){
                    prev->next=temp;
                }
                break;
            }
            ListNode* nexxt=kthnode->next;
            kthnode->next=nullptr;
            reverse(temp);
            if (temp==head){
                head=kthnode;
            }
            else{
                prev->next=kthnode;
            }
            prev=temp;
            temp=nexxt;
        }
        return head;
    }
};