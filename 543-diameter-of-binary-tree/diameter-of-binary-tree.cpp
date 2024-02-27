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
    int solve(TreeNode* root, int &ans)
    {
        if(root==nullptr)
            return 0;
        int left_dia=solve(root->left,ans);
        int right_dia=solve(root->right,ans);
        ans=max(ans,left_dia+right_dia);
        return max(left_dia,right_dia)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};