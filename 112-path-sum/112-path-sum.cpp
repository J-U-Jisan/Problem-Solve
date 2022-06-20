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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        
        stack<pair<TreeNode*, int> > st;
        st.push(make_pair(root,targetSum - root->val));
        
        while(!st.empty()){
            root = st.top().first;
            int val = st.top().second;
            st.pop();
            
            if(root->left){
                st.push(make_pair(root->left, val - root->left->val));
            }
            
            if(root->right){
                st.push(make_pair(root->right, val - root->right->val));
            }
            if(val==0 && root->left == nullptr && root->right == nullptr)
                return true;
        }
        return false;
    }
};