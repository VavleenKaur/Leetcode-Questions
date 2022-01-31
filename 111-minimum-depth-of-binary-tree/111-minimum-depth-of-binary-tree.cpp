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
    int minDepth(TreeNode* root) {
        int minm=INT_MAX;
        inorder(root,1,minm);
        return (minm!=INT_MAX)?minm:0;
    }
    
    void inorder(TreeNode* root,int len,int &minm)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,len+1,minm);
        if(root->left==NULL &&root->right==NULL)
        {
            minm=min(minm,len);
        }
        inorder(root->right,len+1,minm);
    }
    
};