class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        first = dummy
        second = dummy

        for _ in range(n + 1):
            if first is None:
                return head
            first = first.next

        while first is not None:
            first = first.next
            second = second.next

        second.next = second.next.next

        return dummy.next

def create_linked_list(nums):
    dummy = ListNode()
    current = dummy
    for num in nums:
        current.next = ListNode(num)
        current = current.next
    return dummy.next

def print_linked_list(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")

if __name__ == "__main__":
    nums = list(map(int, input("Enter space-separated numbers to create a linked list: ").split()))
    head = create_linked_list(nums)
    print("Original linked list:")
    print_linked_list(head)
    n = int(input("Enter the value of n: "))
    solution = Solution()
    head = solution.removeNthFromEnd(head, n)
    print("Linked list after removing the nth node from the end:")
    print_linked_list(head)
