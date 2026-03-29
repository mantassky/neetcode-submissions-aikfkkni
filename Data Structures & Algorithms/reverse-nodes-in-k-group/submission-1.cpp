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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // if (k == 1) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prevEnd = dummy;
        ListNode* start = head;
        ListNode* end = head;
        int count = 1;
        
        while (end != nullptr) {
            if (count == k) {
                reverseGroup(start, end, prevEnd);
                // end and start have switched in the list
                count = 1;
                prevEnd = start;
                start = start->next;
                end = start;
            } else {
                count++;
                end = end->next;
            }
        }

        return dummy->next;
    }

    void reverseGroup(
        ListNode* start,
        ListNode* end,
        ListNode* prevEnd
    ) {
        ListNode* prev = prevEnd;
        ListNode* curr = start;

        ListNode* abc = end->next;
        while (curr != abc) {
            ListNode* nextCurr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextCurr;
        }

        start->next = curr;
        if (prevEnd != nullptr)
            prevEnd->next = end;
    }
};
