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
    int dfs(TreeNode *root, bool isLeft)
    {
        if(root==nullptr)
            return 0;
        if(root->left==nullptr && root->right==nullptr) // if node has no child nodes
            return isLeft==1?root->val:0;   // if the node is LEFT node
        return dfs(root->left,true) + dfs(root->right,false); 
    }
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        return dfs(root,false);
    }
};