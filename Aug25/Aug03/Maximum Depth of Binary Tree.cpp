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
    int helper(TreeNode* &root){
        if(root == NULL){
            return 0;
        }
        int leftCount = helper(root->left);
        int rightCount = helper(root->right);

        return 1 + max(leftCount,rightCount);
    }
    int maxDepth(TreeNode* root) {
       int answer =  helper(root);

        return answer;
    }
};