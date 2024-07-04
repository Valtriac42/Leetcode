class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def depth(self, root):
        if root is None:
            return 0
        else:
            left_depth = self.depth(root.left)
            right_depth = self.depth(root.right)

            self.diameter = max(self.diameter, left_depth + right_depth)

            return max(left_depth, right_depth) + 1

    def diameterOfBinaryTree(self, root):
        self.diameter = 0
        self.depth(root)
        return self.diameter

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.left.right.left = TreeNode(6)
root.left.right.right = TreeNode(7)

solution = Solution()
print(solution.diameterOfBinaryTree(root)) 
