# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p, q):
        if not p and not q:
            return True
        if not p or not q:
            return False
        return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

# Example usage:
if __name__ == "__main__":
    # Create some example trees
    # Tree 1
    p = TreeNode(1)
    p.left = TreeNode(2)
    p.right = TreeNode(3)

    # Tree 2
    q = TreeNode(1)
    q.left = TreeNode(2)
    q.right = TreeNode(3)

    solution = Solution()
    print(solution.isSameTree(p, q))  # Output: True
