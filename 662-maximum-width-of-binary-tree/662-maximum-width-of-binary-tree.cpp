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
    int widthOfBinaryTree(TreeNode* root) {
        //level order traversal
        if(root==NULL){return 0;}
        int maxWidth=0;
        queue<pair<TreeNode*,long long int>>q;
        
        q.push({root,0});
        while(!q.empty())
        {   long long int minm=q.front().second;
            int first,last,size=q.size();
            for(int i=0;i<size;i++)
            {  
               long long int cur_ind=q.front().second-minm; //avoid overflow 0-> 123 1->0->123 
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0){first=cur_ind;}
                if(i==size-1){last=cur_ind;}
                if(node->left){q.push({node->left,cur_ind*2+1});}
                if(node->right){q.push({node->right,cur_ind*2+2});}
                
            }
         maxWidth=max(maxWidth,last-first+1);
         
        }
        return maxWidth;
    }
};