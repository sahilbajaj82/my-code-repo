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
    int ans;
    int c;
public:
    int traverse(TreeNode * root ,int k) {
        if(root==NULL) {
            return 0;
        }
        int left=traverse(root->left,k);
        c++;
        if(c==k) {
            ans=root->val;
        }
        int right=traverse(root->right,k);
        
        return left+right+1;
    }
    int kthSmallest(TreeNode* root, int k) {
        c=0;
        traverse(root,k);
        return ans;
    }
};
