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
        // calculate size
        int n = 0;
        ListNode* start = new ListNode(0, head);
        while (head != nullptr) {
            n++;
            head = head->next;
        }

        // separate halves
        head = start->next;
        for (int i = 0; i < n / 2; i ++)
            head = head->next;
        
        ListNode* head2 = head->next;
        head->next = nullptr;
        head = start->next;

        // reverse the second half
        ListNode* prev = nullptr;
        while (head2 != nullptr) {
            ListNode* tempNext = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = tempNext;
        }

        // merge the halves
        head2 = prev;
        while (head2 != nullptr) {
            ListNode* tempNext = head->next;
            head->next = head2;
            head2 = head2->next;
            head->next->next = tempNext;
            head = tempNext;
        }

        head = start->next;
    }
};
