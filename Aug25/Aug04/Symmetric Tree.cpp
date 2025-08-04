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
    bool check(TreeNode* x, TreeNode* y){
        if(!x && !y) return true; // same means mirrot
        if(!x || !y) return false;
        if(x->val != y->val) return false;

        return check(x->left,y->right) && check(x->right,y->left);
    }
    bool isSymmetric(TreeNode* root) {

        if(!root)return true;

        return check(root->left,root->right);
        
    }
};