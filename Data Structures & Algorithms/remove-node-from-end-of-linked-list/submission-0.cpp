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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            size ++;
            temp = temp->next;
        }

        int rAway = size - n;
        temp = head;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            if (rAway == 0) {
                if (prev == nullptr) return temp->next;
                prev->next = temp->next;
                return head;
            }
            rAway--;
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};
