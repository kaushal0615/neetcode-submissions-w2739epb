# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        self.mp = {}
        self.inorder = inorder
        self.preorder = preorder
        for i in range(0, len(self.inorder)):
            self.mp[self.inorder[i]] = i

        def build(mp, preorder, preStart, preEnd, inorder, inStart, inEnd):
            if preStart>preEnd or inStart>inEnd:
                return None
            root = TreeNode(self.preorder[preStart])
            index = self.mp[root.val]
            length = index - inStart
            root.left = build(self.mp, self.preorder, preStart+1, preStart+length, self.inorder, inStart, index-1)
            root.right = build(self.mp, self.preorder, preStart+length+1, preEnd, self.inorder, index+1, inEnd)
            return root
        
        root = build(self.mp, self.preorder, 0, len(preorder)-1, self.inorder, 0, len(inorder)-1)
        return root