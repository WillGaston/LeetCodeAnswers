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
    ListNode* rotateRight(ListNode* head, int k) {
        // pointer for end of list, pointer for computing new head
        int numNodes = 1;
        ListNode* end = head;
        ListNode *newHead = head;
        ListNode *prev = NULL;

        if (!head || !head->next | k == 0) return head;

        while (end->next) {
            numNodes++;
            end = end->next;
        }

        int relativeOffset = k % numNodes;

        if (relativeOffset == 0) return head;

        for (int i = 0; i < numNodes - relativeOffset; i++) {
            prev = newHead;
            newHead = newHead->next;
        }

        if (prev != NULL) prev->next = NULL;
        end->next = head;
        head = newHead;
        return head;
    }
};
