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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        return reserve(head);
    }
private:
    ListNode* reserve(ListNode* current) {
        if (current->next == nullptr) {
            return current;
        }
        ListNode* newHead = reserve(current->next);
        current->next->next = current;
        current->next = nullptr;
        return newHead;
    }
};