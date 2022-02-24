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
       TreeNode* helper(vector<int>& arr, int si, int ei)
    {
        if(si > ei) return NULL;
        int mid = (si+ei)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = helper(arr,si,mid-1);
        root->right = helper(arr,mid+1,ei);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        if(arr.size() == 0) return NULL;
        return helper(arr,0,arr.size()-1);
    } 
};