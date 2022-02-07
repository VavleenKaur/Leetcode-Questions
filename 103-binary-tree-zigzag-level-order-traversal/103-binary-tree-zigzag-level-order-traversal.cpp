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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> v2;
        if(root==NULL)
        {
            return v2;
        }
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
        while(!q.empty())
        {
            vector<int>v1;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                v1.push_back(node->val);
               if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            if(flag==1)
            {
                reverse(v1.begin(),v1.end());
                
            }
            v2.push_back(v1);
            flag=!flag;
        }
        return v2;
    }
};