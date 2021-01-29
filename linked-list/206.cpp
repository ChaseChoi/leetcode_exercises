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
        return reserve(head);
    }
private:
    ListNode* reserve(ListNode* current) {
        ListNode* head = current, tail = nullptr;
        while (current != nullptr) {
            head = current->next;
            current->next = tail;
            tail = current;
            current = head;
        }

        return tail;
    }
};