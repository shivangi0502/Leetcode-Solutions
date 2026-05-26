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

    bool res = false;
    void hps(TreeNode*root, int sum, int targetSum){
        
        //root is null
        if(root == nullptr) return;
        sum = sum + root->val;
        //leaf node condition check
        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                res = true;
                return;
            }
        }
        //not a leaf node
        hps(root->left,sum,targetSum);

        hps(root->right,sum,targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        hps(root,0,targetSum);
        return res;
    }
};
