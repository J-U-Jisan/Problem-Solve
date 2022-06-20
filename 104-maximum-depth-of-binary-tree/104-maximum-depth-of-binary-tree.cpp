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
    int maxDepth(TreeNode* root) {
       unordered_map<TreeNode*, int> d;
       queue<TreeNode*> q;
       if(root){
           q.push(root);
           d[root]=1;
       }
       while(!q.empty()){
           int sz = q.size();
           for(int i=0;i<sz;i++){
               root = q.front();
               q.pop();
               if(root->left){
                   d[root->left] = d[root] + 1;
                   q.push(root->left);
               }
               if(root->right){
                   d[root->right] = d[root] + 1;
                   q.push(root->right);
               }
           }
       }
       int mx = 0;
       for(auto x:d){
           mx = max(mx, x.second);
       }
       return mx;
    }
};