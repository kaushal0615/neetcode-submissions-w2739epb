# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        cnt  = 0
        q = deque()
        q.append((root, float('-inf')))
        while q:
            node, maxVal = q.popleft()
            if node.val >= maxVal:
                cnt += 1
            newVal = max(maxVal, node.val)
            if node.left:
                q.append((node.left, newVal))
            if node.right:
                q.append((node.right, newVal))
        return cnt


    
