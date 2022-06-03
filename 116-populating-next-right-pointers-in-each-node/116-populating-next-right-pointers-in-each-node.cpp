/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(!root)
            return root;
        
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            Node *node = q.front();
            Node *temp;
            q.pop();
            for(int i=1;i<sz;i++){
                temp = q.front();
                node->next = temp;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
                q.pop();
                node = temp;
            }
            if(node->left)
                    q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return root;
    }
};