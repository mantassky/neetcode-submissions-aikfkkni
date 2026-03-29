/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* indexHead = new Node(0);
        Node* resHead = new Node(head->val);

        Node* tempInit = head;
        Node* tempIndex = indexHead;
        Node* tempRes = resHead;

        while (tempInit != nullptr) {
            // cout << tempInit->val << endl;
            tempIndex->random = tempInit; // index rand to init
            Node* nextInit = tempInit->next;
            tempInit->next = tempRes; // init next to res

            if (nextInit == nullptr) break;
            // create next and move index
            tempIndex->next = new Node(0);
            tempIndex = tempIndex->next;

            // create next and move res
            tempRes->next = new Node(nextInit->val);
            tempRes = tempRes->next;

            // move init
            tempInit = nextInit;
        }

        tempIndex = indexHead;
        while (tempIndex != nullptr) {
            Node* randDest = tempIndex->random->random;
            if (randDest != nullptr) {
                Node* tempRes = tempIndex->random->next;
                tempRes->random = randDest->next;
            }
            tempIndex = tempIndex->next;
        }
        tempIndex = indexHead;
        while (tempIndex != nullptr) {
            if (tempIndex->next == nullptr) {
                tempIndex->random->next = nullptr;
                break;
            }
            tempIndex->random->next = tempIndex->next->random;
            tempIndex = tempIndex->next;
        }

        return resHead;
    }
};
