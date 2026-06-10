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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=nullptr;

        while(temp!=nullptr){
           
            bool duplicate=false;
            while(temp->next && temp->val == temp->next->val){
                duplicate=true;
                temp=temp->next;
                
            }
            if (duplicate){
            if (prev!=nullptr){
                prev->next=temp->next;
                
            }
            else{
                head=temp->next;
            }}
            else{
            prev=temp;
        }
        temp=temp->next;
        }
       return head; 
    }
};