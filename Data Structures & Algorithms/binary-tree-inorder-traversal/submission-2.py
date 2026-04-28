# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root: Optional[TreeNode], ans: List[int]):
        if not root:
            return
        self.solve(root.left, ans)
        ans.append(root.val)
        self.solve(root.right, ans)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        self.solve(root, ans)
        return ans