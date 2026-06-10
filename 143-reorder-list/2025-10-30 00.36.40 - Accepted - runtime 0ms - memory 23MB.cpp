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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = nullptr;
        ListNode* cur = slow->next;
        slow->next = nullptr;
        
        ListNode* next;
        while(cur!=nullptr){
            next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }

        ListNode* h1 = head;
        ListNode* h2 = prev;

        while(h1 != nullptr && h2 != nullptr){
            ListNode* h1t = h1 -> next;
            ListNode* h2t = h2 -> next;

            h1->next = h2;
            if(h1t == nullptr) break;
            h2->next = h1t;
            if(h2t == nullptr) break;

            h1 = h1t;
            h2 = h2t;
        }
    }
};