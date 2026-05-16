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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftTOright =1;
        while(!q.empty()){
            int lvl_size = q.size();
            vector<int> temp(lvl_size);
            int first =0;
            int last = lvl_size-1;
            while(lvl_size--){
                TreeNode*t = q.front();
                q.pop();
                if(leftTOright==1){
                    temp[first] = t->val;
                    first++;
                }
                else{
                    temp[last] = t->val;
                    last--;
                }
                if(t->left!=nullptr){
                    q.push(t->left);
                }
                if(t->right!=nullptr){
                    q.push(t->right);
                }
            }
            res.push_back(temp);
            leftTOright = 1-leftTOright;
        }
        return res;
        
    }
};
