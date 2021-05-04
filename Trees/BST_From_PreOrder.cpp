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
    
    // O(n)
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int root_idx = 0;
        return bstHelper(preorder,INT_MIN,INT_MAX,root_idx);
    }
    TreeNode* bstHelper(vector<int>& preorder, int lower_bound, int upper_bound, int& root_idx){
        if(root_idx==preorder.size()){
            return NULL;
        }
        int root_value = preorder[root_idx];
        if(root_value  < lower_bound || root_value> upper_bound){
            return NULL;
        }
        ++root_idx;
        
        auto left_subtree = bstHelper(preorder,lower_bound,root_value,root_idx);
        auto right_subtree= bstHelper(preorder,root_value,upper_bound,root_idx);
        
        TreeNode* root = new TreeNode(root_value,left_subtree,right_subtree);
        return root;
        
    }
