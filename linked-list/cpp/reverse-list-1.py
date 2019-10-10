# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        temp_pre = None
        temp = head
        while(temp is not None):
            n = temp.next
            temp.next = temp_pre
            temp_pre = temp
            temp = n
        head = temp_pre
        return head