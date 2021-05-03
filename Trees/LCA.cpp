 struct status{
    int num_nodes;
    TreeNode* ancestor;
};
 status LCA(TreeNode* root,int p, int q){
        if(root==nullptr) return {0,nullptr};
        auto left_num_nodes = LCA(root->left,p,q);
        if(left_num_nodes.num_nodes==2) return left_num_nodes;
        auto right_num_nodes = LCA(root->right,p,q);
        if(right_num_nodes.num_nodes==2) return right_num_nodes; 
        int num_nodes = left_num_nodes.num_nodes + right_num_nodes.num_nodes
                        + (root->val==p) + (root->val==q);    
        return {num_nodes,(num_nodes==2)?root:nullptr};
}
int Solution::lca(TreeNode* A, int B, int C) {
    TreeNode* ret = LCA(A,B,C).ancestor;
    if(ret==NULL) return -1;
    return ret->val;
}
