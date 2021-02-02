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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(), *prev = head;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            prev->next = new ListNode(sum);
            l1 = l1->next;
            l2 = l2->next;
            prev = prev->next;
        }
        while (l1) {
            int sum = l1->val + carry;
            carry = sum / 10;
            sum %= 10;
            prev->next = new ListNode(sum);
            l1 = l1->next;
            prev = prev->next;
        }
        while (l2) {
            int sum = l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            prev->next = new ListNode(sum);
            l2 = l2->next;
            prev = prev->next;
        }
        if (carry)
            prev->next = new ListNode(carry);
        return head->next;
    }
};