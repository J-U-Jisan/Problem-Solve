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
    bool findTarget(TreeNode* root, int k) {
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
                    temp->right = NULL;
                    root = root->right;
                }
            }
            else{
                v.push_back(root->val);
                root = root->right;
            }
        }
        for(int i=0, j=v.size()-1;i<j;){
            int a  = k-v[i];
            if(a==v[j])
                return true;
            else if(a>v[j])
                i++;
            else j--;
        }
        return false;
    }
};