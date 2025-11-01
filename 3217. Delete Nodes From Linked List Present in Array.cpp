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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        map<int, int> in;

        for (int num : nums) {
            in[num] = 1;
        }

        ListNode *curr = head;
        ListNode *prev = &dummy;

        while (curr) {
            if (in[curr->val] == 0) {
                prev = curr;
            } else {
                prev->next = curr->next;
            }
            curr = curr->next;
        }

        return dummy.next;
    }
};
