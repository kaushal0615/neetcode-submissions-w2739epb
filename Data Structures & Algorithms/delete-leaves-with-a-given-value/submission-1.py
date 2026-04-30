# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        def dfs(root, target):
            if not root:
                return None
            root.left = dfs(root.left, target)
            root.right = dfs(root.right, target)
            if root.left is None and root.right is None and root.val is target:
                return None
            return root
        return dfs(root, target)