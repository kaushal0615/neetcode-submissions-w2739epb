# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
    
        def solve(node):          # plain function, not a method
            if not node:
                return
            solve(node.left)      # no self needed ✅
            ans.append(node.val)
            solve(node.right)
    
        solve(root)
        return ans
        