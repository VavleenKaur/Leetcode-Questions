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
    
    int diameterOfBinaryTree(TreeNode* root) {
        //return diamter -> max length from one node to another may or may  not including root
          //hence take max of lh+rh of every node
        int maxDiameter=0;
        height(root,maxDiameter);
        return maxDiameter;
        
    }
    int height(TreeNode* root, int &maxDiameter)
    { //height return max(lh,rh)+1
        if(root==NULL)
        {
            return 0;
        }
        int lh=height(root->left,maxDiameter);
        int rh=height(root->right,maxDiameter);
        maxDiameter=max(maxDiameter,lh+rh);
        return 1+max(lh,rh);
    }
};