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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>nodes;
        unordered_map<TreeNode*, TreeNode*>mp;
        
        while(root){
            if(root->left && mp.find(root->left) ==mp.end()){
                mp[root->left] = root;
                root = root->left;
            }
            else if(root->right && mp.find(root->right)==mp.end()){
                mp[root->right] = root;
                root = root->right;
            }
            else{
                nodes.push_back(root->val);
                root = mp[root];
            }
        }
        mp.clear();
        return nodes;
    }
};