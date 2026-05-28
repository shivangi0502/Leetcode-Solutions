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

    TreeNode* prev = nullptr;
    TreeNode* g1first = nullptr;
    TreeNode* g1second = nullptr;
    TreeNode* g2first = nullptr;
    TreeNode* g2second = nullptr;
    int g = 0;
    void ino(TreeNode* root){
        if(root == nullptr) return;
        ino(root->left);
        if(prev == nullptr){
            prev = root;
        }
        else{
            if(root->val <= prev->val){
                if(g==0){
                    g1first = prev;
                    g1second = root;
                    g++;
                }
                else{
                    g2first = prev;
                    g2second = root;
                    g++;
                }
            }
            prev = root;
        }
        ino(root->right);
    }

    void recoverTree(TreeNode* root) {
        ino(root);
        if(g==1){
            swap(g1first->val,g1second->val);
        }
        else{
            swap(g1first->val,g2second->val);
        }
    }
};
