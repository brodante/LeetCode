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
    string dfs(TreeNode *root, string curr)
    {
        if(!root)
            return "";
        //curr=(string)((char)('a'+root->val)+curr); //I hope there's a better way lmao
        curr=(char)('a'+root->val)+curr;
        if(root->left&&root->right)
        {
            return min(dfs(root->left,curr), dfs(root->right,curr));
        }
        if(root->right)
            return dfs(root->right,curr);
        if(root->left)
            return dfs(root->left,curr);
        return curr;
    }
public:
    string smallestFromLeaf(TreeNode* root)
    {
        return dfs(root,"");
    }
};