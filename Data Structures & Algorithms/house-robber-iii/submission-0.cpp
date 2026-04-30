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
    pair<int, int> solve(TreeNode* root){
        if(root == NULL) return {0,0};
        auto [lroot, lnotroot] = solve(root->left);
        auto [rroot, rnotroot] = solve(root->right);
        int withRoot = root->val + lnotroot + rnotroot;
        int withoutRoot = max(lroot, lnotroot) + max(rroot, rnotroot);
        return {withRoot, withoutRoot};
    }
    int rob(TreeNode* root) {
        auto [withRoot, withoutRoot] = solve(root);
        return max(withRoot, withoutRoot);
    }
};