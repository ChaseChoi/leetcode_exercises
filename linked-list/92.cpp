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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head->next == nullptr) {
            return head;
        }
        ListNode*  totalHead = nullptr;
        if (m != 1) {
            iterate(head, 1, m, n);
            tempTail->next = tail;
            return head;
        } else {
            totalHead = reverse(head, m, n);
            tempTail = head;
            tempTail->next = tail;
            return totalHead;
        }
    }

private:
    ListNode *tail = nullptr, *tempTail;
    ListNode* iterate(ListNode* current, int start, int m, int n) {
        if (start == m - 1) {
            tempTail = current->next;
            current->next = reverse(current->next, m, n);
            return current;
        }

        return iterate(current->next, start + 1, m, n);
    }

    ListNode* reverse(ListNode* current, int start, int end) {
        if (start == end) {
            tail = current->next;
            return current;
        }

        ListNode* newHead = reverse(current->next, start + 1, end);
        current->next->next = current;
        current->next = nullptr;
        return newHead;
    }
};