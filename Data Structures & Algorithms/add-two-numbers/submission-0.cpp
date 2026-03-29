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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        // find counts
        int count1 = 0;
        int count2 = 0;
        while (temp1 != nullptr || temp2 != nullptr) {
            if (temp1 != nullptr) {
                count1++;
                temp1 = temp1->next;
            }
            if (temp2 != nullptr) {
                count2++;
                temp2 = temp2->next;
            }
        }
        if (count1 < count2) swap(l1, l2);
        
        // get sum
        temp1 = l1;
        temp2 = l2;
        int carry = 0;
        while (temp2 != nullptr) {
            int digitSum = temp1->val + temp2->val + carry;
            carry = digitSum / 10;

            temp1->val = digitSum % 10;

            if (temp1->next == nullptr && carry) {
                temp1->next = new ListNode(1);
                carry = 0;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (carry) {
            int digitSum = temp1->val + carry;
            carry = digitSum / 10;
            temp1->val = digitSum % 10;

            if (temp1->next == nullptr && carry) {
                temp1->next = new ListNode(1);
                carry = 0;
            }
            temp1 = temp1->next;
        }

        return l1;
    }
};
