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
    bool helper(TreeNode* root,int k,unordered_set<int> &check){
        if(!root){
            return false;
        }

        if(check.count(k - root->val)){
            return true;
        }

        check.insert(root->val);

        return helper(root->left,k,check) || helper(root->right,k,check);
    }
    bool findTarget(TreeNode* root, int k) {
      unordered_set<int>check;
       return helper(root,k,check);
    }

};