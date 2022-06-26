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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* pre=NULL;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;    
            }
            root = st.top();
            st.pop();
            if(pre && pre->val >= root->val)
                return false;
            
            pre = root;
            root = root->right;
        }
        
        return true;    
    }
};