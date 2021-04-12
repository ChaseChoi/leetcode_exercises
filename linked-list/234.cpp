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
    bool isPalindrome(ListNode* head) {
        if (!head && !head->next) {
            return true;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow) {
            if (head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode *tail = nullptr, *temp;
        while (head) {
            temp = head->next;
            head->next = tail;
            tail = head;
            head = temp;
        }
        return tail;
    }
};