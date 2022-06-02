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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> lt;
        stack<TreeNode*> rt;
        
        TreeNode *rootl, *rootr;
        if(root->left != nullptr && root->right != nullptr && root->left->val == root->right->val){
            lt.push(root->left);
            rt.push(root->right);
        }
        else if(root->left == nullptr && root->right == nullptr)
            return true;
        else{
            return false;
        }
        
        
        while(!lt.empty() && !rt.empty()){
            rootl = lt.top();
            lt.pop();
            rootr = rt.top();
            rt.pop();
           
            if(((rootl->left == nullptr && rootr->right == nullptr)||
                (rootl->left != nullptr && rootr->right != nullptr && 
               rootl->left->val == rootr->right->val ))&&
               ((rootl->right == nullptr && rootr->left == nullptr)||
                (rootl->right != nullptr && rootr->left != nullptr && 
               rootl->right->val == rootr->left->val))){
                if(rootl->left != nullptr)
                    lt.push(rootl->left);
                if(rootr->left != nullptr)     
                    lt.push(rootr->left);
                if(rootr->right != nullptr)     
                    rt.push(rootr->right);
                if(rootl->right != nullptr)
                    rt.push(rootl->right);
            }
            else if(rootl->left == nullptr && rootl->right == nullptr && rootr->left == nullptr && rootr->right == nullptr){
                return true;
            }
            else return false;
        }  
        return true;
    }
};