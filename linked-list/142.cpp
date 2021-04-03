/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        bool flag = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                flag = true;
                break;
            }
        }

        if (flag) {
            fast = head;
            while (true) {
                if (fast == slow) {
                    return fast;
                }
                fast = fast->next;
                slow = slow->next;
            }
        }
        return nullptr;
    }
};