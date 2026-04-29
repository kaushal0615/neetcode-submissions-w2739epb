# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.k = k
        if not root:
            return -1
        left = self.kthSmallest(root.left, self.k)    
        if left != -1:
            return left
        self.k -= 1
        if self.k == 0:
            return root.val
        return self.kthSmallest(root.right, self.k)

