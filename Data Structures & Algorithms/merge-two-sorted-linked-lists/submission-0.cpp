class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* newHead;

        if (list1->val <= list2->val) {
            newHead = list1;
            temp1 = list1->next;
        }
        else {
            newHead = list2;
            temp2 = list2->next;
        }

        ListNode* temp = newHead;

        while (temp1 != nullptr && temp2 != nullptr) {

            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            }
            else {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }

        if (temp1 != nullptr)
            temp->next = temp1;
        else
            temp->next = temp2;

        return newHead;
    }
};