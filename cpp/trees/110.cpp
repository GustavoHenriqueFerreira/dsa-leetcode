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
    bool isBalanced(TreeNode* root) {
        int res = checarDiferenca(root);

        if (res == -1)
            return false;

        return true; 
    }

    int checarDiferenca(TreeNode* root) {
        if (!root) 
            return 0;
        
        int esq = checarDiferenca(root->left);
        int dir = checarDiferenca(root->right);

        if (esq == -1 || dir == -1)
            return -1;

        if (abs(esq - dir) > 1)
            return -1;
        
        return 1 + max(esq, dir);
    }
};