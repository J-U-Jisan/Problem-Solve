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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > output;
        vector<int> temp;
        queue<pair<TreeNode*, int> >q;
        
        if(!root)
            return output;
        
        q.push(make_pair(root, 0));
        
        
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            if(output.size()>level){
                output[level].push_back(node->val);
            }
            else{
                temp.push_back(node->val);
                output.push_back(temp);
                temp.clear();
            }
            q.pop();
            if(node->left != nullptr){
                q.push(make_pair(node->left, level+1));
            }
                
            if(node->right != nullptr){
                q.push(make_pair(node->right, level+1));
            }
            
        }
        return output;
    }
};