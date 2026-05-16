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
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        if(root==nullptr) return res;
        while(!q.empty()){
            int lvl_size = q.size();
            vector<int> temp;
            while(lvl_size--){
                TreeNode*t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left!=nullptr){
                    q.push(t->left);
                }
                if(t->right!=nullptr){
                    q.push(t->right);
                }
            }
            res.push_back(temp);
        }
        return res;
        
    }
};
