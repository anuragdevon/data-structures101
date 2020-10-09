//Question link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Solution-

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void in(vector<int>& v,TreeNode* root){
        if(root==NULL)
            return ;
        in(v,root->left);
        v.push_back(root->val);
                in(v,root->right);

    }
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int > v;
        in(v,root);
        
        return v[k-1];
        
        
    }
};
