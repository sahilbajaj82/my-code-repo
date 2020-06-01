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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) {
            return root;
        }
        TreeNode *temp1=root->left;
        TreeNode *temp2=root->right;
        invertTree(root->left);
        invertTree(root->right);
        root->left=temp2;
        root->right=temp1;
        return root;
    }
};
