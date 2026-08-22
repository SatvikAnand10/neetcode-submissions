class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        if (isequal(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

private:
    bool isequal(TreeNode* a, TreeNode* b) {
        if (!a || !b) return a == b;

        if (a->val != b->val) return false;

        return isequal(a->left, b->left) &&
               isequal(a->right, b->right);
    }
};