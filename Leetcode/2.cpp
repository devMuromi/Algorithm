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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode(l1->val + l2->val);
        ListNode *cur = ret;
        while (l1->next || l2->next) {
            cur->next = new ListNode();
            cur = cur->next;
            if (l1->next != nullptr && l2->next != nullptr) {
                l1 = l1->next;
                l2 = l2->next;
                cur->val = l1->val + l2->val;
            } else if (l1->next != nullptr) {
                l1 = l1->next;
                cur->val = l1->val;
            } else if (l2->next != nullptr) {
                l2 = l2->next;
                cur->val = l2->val;
            }
        }
        cur = ret;
        while (cur->next || cur->val >= 10) {
            if (cur->val >= 10) {
                if (cur->next == nullptr) {
                    cur->next = new ListNode(1);
                } else {
                    cur->next->val += 1;
                }
                cur->val -= 10;
            }
            cur = cur->next;
        }
        return ret;
    }
};