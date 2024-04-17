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
private:
    int spsc(TreeNode *root, int tmp)
    {
        if(!root)
            return 0;
        tmp=(tmp*10)+root->val;
        if(!root->left&&!root->right)
            return tmp;
        return spsc(root->left,tmp)+spsc(root->right,tmp);
    }
public:
    int sumNumbers(TreeNode* root)
    {
        return spsc(root, 0);
    }
};