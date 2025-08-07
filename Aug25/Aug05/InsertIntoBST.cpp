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
    void helper(TreeNode* &root,int val){
        if(!root) return;
        TreeNode* temp = new TreeNode(val);

        if(val > root->val){
            if(!root->right){
                root->right = temp;
                return;
            }else{
                helper(root->right,val);
            }
        }else{
            if(!root->left){
                root->left = temp;
                return;
            }else{
                helper(root->left,val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(!root){
            root = new TreeNode(val);
            return root;
        }

        helper(root,val);

        return root;
        
    }
};