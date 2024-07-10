class Solution:
    def add(self, root, val, depth, curr):
        if not root:
            return None

        if curr == depth - 1:
            lTemp = root.left
            rTemp = root.right

            root.left = TreeNode(val)
            root.right = TreeNode(val)
            root.left.left = lTemp
            root.right.right = rTemp

            return root

        root.left = self.add(root.left, val, depth, curr + 1)
        root.right = self.add(root.right, val, depth, curr + 1)

        return root

    def addOneRow(self, root, val, depth):
        if depth == 1:
            newRoot = TreeNode(val)
            newRoot.left = root
            return newRoot

        return self.add(root, val, depth, 1)

# Usage
# Assuming TreeNode class is defined elsewhere
# Prompt user for inputs
val = int(input("Enter value for new nodes: "))
depth = int(input("Enter depth: "))
# You'd need to have root defined before using addOneRow method
# Then you can call the method like:
# solution = Solution()
# result = solution.addOneRow(root, val, depth)
