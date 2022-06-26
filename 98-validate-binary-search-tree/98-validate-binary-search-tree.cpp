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
        vector<int>v;
        while(root){
            if(root->left){
                TreeNode* temp = root->left;
                while(temp->right && temp->right != root){
                    temp = temp->right;
                }
                if(!temp->right){
                    temp->right = root;
                    root = root->left;
                }
                else{
                    v.push_back(root->val);
                    root = root->right;
                    temp->right = NULL;
                }
            }
            else{
                v.push_back(root->val);
                root = root->right;
            }
        }
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1])
                return false;
        }
        return true;    
    }
};