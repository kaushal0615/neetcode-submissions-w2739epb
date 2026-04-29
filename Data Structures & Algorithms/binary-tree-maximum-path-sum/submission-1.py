# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.maxSum = float('-inf')
        
        def solve(root):
            # nonlocal maxSum
            if not root:
                return 0
            left = solve(root.left)
            right = solve(root.right)
            left_and_right_both = left + right + root.val
            left_or_right = max(left, right) + root.val
            only_root = root.val
            self.maxSum = max({self.maxSum, left_and_right_both, left_or_right, only_root})
            return max(left_or_right, only_root)

        solve(root)
        return self.maxSum