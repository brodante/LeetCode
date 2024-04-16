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
    TreeNode *bfs(TreeNode*root, int val, int depth, int curr)
    {
        if(root==nullptr)
            return nullptr;
        if(curr==depth-1)
        {
            TreeNode *leftTemp= root->left;
            TreeNode *rightTemp= root->right;

            root->left= new TreeNode(val);
            root->right= new TreeNode(val);

            root->left->left=leftTemp;
            root->right->right=rightTemp;

            return root;
        }
        root->left= bfs(root->left,val,depth,curr+1);
        root->right= bfs(root->right,val,depth,curr+1);

        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if(depth==1)
        {
            TreeNode *tmp= new TreeNode(val);
            tmp->left=root;
            return tmp;
        }
        int curr=1; //current depth = 1 cuz root
        return bfs(root, val, depth, curr);
    }
};