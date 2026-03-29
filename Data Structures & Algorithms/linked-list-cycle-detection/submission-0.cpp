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
    bool hasCycle(ListNode* head) {
        ListNode* sink = new ListNode(2000);

        while (head != nullptr) {
            if (head->val == 2000) return true;

            ListNode* temp = head->next;
            head->next = sink;
            head = temp;
        }

        return false;
    }
};
