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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (!root)
            return res;

        queue<TreeNode*> fila;
        fila.push(root);

        while (!fila.empty()) {
            int size = fila.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = fila.front();

                fila.pop();

                // último nó do nível
                if (i == size - 1)
                    res.push_back(node->val);

                if (node->left)
                    fila.push(node->left);
                if (node->right)
                    fila.push(node->right);
            }
        }

        return res;
    }
};