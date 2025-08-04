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
    void helper(TreeNode* p,TreeNode*q,bool &trigger){
       if(!trigger){
        return;
       }
       if(q && p){
            if(q->val != p->val){
                trigger = false;
                return;
            }else if(q->val == p->val){
                trigger = true;
                helper(p->left,q->left,trigger);
                helper(p->right,q->right,trigger);
            }
       }else if(!q && !p){
        trigger = true;
        return;
       }else{
        trigger = false;
        return;
       }

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool answer = true;
        helper(p,q,answer);
        return answer;
    }
};