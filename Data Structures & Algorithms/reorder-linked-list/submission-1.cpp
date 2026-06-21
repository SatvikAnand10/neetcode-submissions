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
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* seon=slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr; 

        while(seon!=nullptr){
            ListNode* temp=seon->next;
            seon->next=prev;
            prev=seon;
            seon=temp;
        }

        ListNode* first = head;
        seon=prev;
        while (seon != nullptr) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = seon->next;
            first->next = seon;
            seon->next = tmp1;
            first = tmp1;
            seon = tmp2;
        }
    }
};
