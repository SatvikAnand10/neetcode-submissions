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
        ListNode* fast = head->next;
        ListNode* slow= head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* seon = slow->next;
        ListNode* prev =slow->next= nullptr;

        while(seon){
            ListNode* temp = seon->next;
            seon->next=prev;
            prev=seon;
            seon=temp;
        }

        ListNode* first = head;
        seon=prev;

        while(seon){
            ListNode* t1 = first->next;
            ListNode* t2 = seon->next;

            first->next=seon;
            seon->next=t1;

            first=t1;
            seon=t2;
        }
    }
};
