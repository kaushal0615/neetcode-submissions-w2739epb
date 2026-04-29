/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        int cnt = 0;
        q.push({root, INT_MIN});
        while(!q.empty()){
            auto& [node, maxVal] = q.front();
            q.pop();
            if(node->val >= maxVal) cnt++;
            int newVal = max(maxVal, node->val);
            if(node->left) q.push({node->left, newVal});
            if(node->right) q.push({node->right, newVal});
        }
        return cnt;
    }
};
