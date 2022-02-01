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
    int ans=0;
    
    void helper(TreeNode* root,int &ans,bool ifLeft)
    {
        if(root==NULL)
        {return;}
        if(!root->left && !root->right && ifLeft)
        {
            ans+=root->val;
        }
        helper(root->left,ans,true);
        helper(root->right,ans,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
       if(root==NULL)
       {
           return 0;
       }
       helper(root,ans,false);
        return ans;
    }
};