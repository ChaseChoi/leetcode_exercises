// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// [-1,-7,7,-4,19,6,  -9   ,-5,-2,-5]
// 6
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* pre = head, *current = head->next;
        if (current == nullptr) {
            return nullptr;
        }
        while (current != nullptr) {
            records.insert(pre);

            // existed
            if (records.find(current) != records.end()) {
                return current;
            }

            pre = current;
            current = current->next;
        }
        return nullptr;
    }

private:
    unordered_set<ListNode*> records;
};