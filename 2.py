# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode()
        last = head
        carry = 0
        while l1 != None and l2 != None:
            result = l1.val + l2.val + carry
            carry = result // 10
            current = ListNode(result % 10)
            last.next = current
            last = current
            l1 = l1.next
            l2 = l2.next
        while l1 != None:
            result = l1.val + carry
            carry = result // 10
            current = ListNode(result % 10)
            last.next = current
            last = current
            l1 = l1.next
        while l2 != None:
            result = l2.val + carry
            carry = result // 10
            current = ListNode(result % 10)
            last.next = current
            last = current
            l2 = l2.next
        if carry > 0:
            current = ListNode(1)
            last.next = current
        return head.next