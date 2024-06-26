
  
  struct TreeNode {
      int val;
    TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<TreeNode*>arr;
    void inorder(TreeNode*root){
        if(root==nullptr)return;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
    TreeNode* bst(int l,int n){
        if(l>n)return nullptr;
        int m=(l+n)/2;
        TreeNode* root=arr[m];
        root->left=bst(l,m-1);
        root->right=bst(m+1,n);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root==nullptr)return nullptr;
        inorder(root);
        return bst(0,arr.size()-1);
    }
};
