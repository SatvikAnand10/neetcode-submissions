class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* t1 = head;
        int len = 0;

        while (t1) {
            len++;
            t1 = t1->next;
        }

        int pos = len - n;

        // Removing the head
        if (pos == 0) {
            return head->next;
        }

        ListNode* t2 = head;

        for (int i = 0; i < pos - 1; i++) {
            t2 = t2->next;
        }

        t2->next = t2->next->next;

        return head;
    }
};