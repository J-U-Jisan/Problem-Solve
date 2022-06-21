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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return root;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            root =q.front();
            if(root->val == val)
                return root;
            q.pop();
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        return NULL;
    }
};