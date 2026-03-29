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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        if (lists.size() == 0) return nullptr;

        int minIndex;
        while (true) {
            minIndex = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr) continue;
                if (minIndex == -1 || (lists[minIndex]->val > lists[i]->val))
                    minIndex = i;
            }
            if (minIndex == -1) break;
            curr->next = lists[minIndex];
            curr = curr->next;
            lists[minIndex] = lists[minIndex]->next;
        }

        return res->next;
    }
};
