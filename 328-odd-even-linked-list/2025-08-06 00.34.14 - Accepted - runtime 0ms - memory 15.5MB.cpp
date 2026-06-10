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
    ListNode* oddEvenList(ListNode* head) {
      if (head==nullptr || head->next==nullptr){
        return head;
      }
      ListNode* oddhead=head;
      ListNode* evenstart=head->next;
      ListNode* evenhead=head->next;
      while(evenhead!=nullptr && evenhead->next!=nullptr){
        oddhead->next=evenhead->next;
        oddhead=oddhead->next;
        evenhead->next=oddhead->next;
        evenhead=evenhead->next;
      }
      oddhead->next=evenstart;
      return head;
    }
};