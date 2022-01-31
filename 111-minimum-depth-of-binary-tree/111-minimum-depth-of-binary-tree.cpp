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
        preorder(root,1,minm);
        return (minm!=INT_MAX)?minm:0;
    }
    
    void preorder(TreeNode* root,int len,int &minm)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL &&root->right==NULL)
        {
            minm=min(minm,len);
        }
        preorder(root->left,len+1,minm);
        preorder(root->right,len+1,minm);
    }
    
};