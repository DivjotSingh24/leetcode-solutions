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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fastp=head;
        ListNode* slowp=head;
        for (int i=0;i<n;i++){
            fastp=fastp->next;
            
        }
        if (fastp==nullptr){
            return head->next;
        }
        while(fastp!=nullptr && fastp->next!=nullptr){
            fastp=fastp->next;
            slowp=slowp->next;

        }
        ListNode* del=slowp->next;
        slowp->next=slowp->next->next;
        delete del;
        return head;
        
    }
};