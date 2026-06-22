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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ummy= new ListNode();
        ListNode* urr=ummy;
        int arry=0;

        while(l1 || l2 || arry){
            int v1=(l1) ? l1->val : 0;
            int v2=(l2) ? l2->val : 0;

            int val=v1+v2+arry;
            arry=val/10;
            val=val%10;

            urr->next = new ListNode(val);
            urr = urr->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        ListNode* ans=ummy->next;
        delete ummy;
        return ans;
    }
};
