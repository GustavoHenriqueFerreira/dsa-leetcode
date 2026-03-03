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
    bool compararArvores(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;

        if (p->val != q->val)
            return false;

        bool esq  = compararArvores(p->left, q->left);
        if (!esq) 
            return false;

        bool dir = compararArvores(p->right, q->right);
        if (!dir) 
            return false;

        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        
        if (compararArvores(root, subRoot))
            return true;
        
        return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
    }
};