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
    int maxSum;
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int both_left_and_right = left + right + root->val;
        int left_or_right_max = max(left, right) + root->val;
        int only_root = root->val;
        maxSum = max({maxSum, both_left_and_right, left_or_right_max, only_root});
        return max(left_or_right_max, only_root);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};
