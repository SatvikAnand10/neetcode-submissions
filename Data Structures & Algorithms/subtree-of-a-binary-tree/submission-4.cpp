class Solution {
public:
    bool isEqual(TreeNode* a, TreeNode* b) {
        if (!a || !b) return a == b;

        if (a->val != b->val) return false;

        return isEqual(a->left, b->left) &&
               isEqual(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;

        if (isEqual(root, subRoot)) return true;

        if (isSubtree(root->left, subRoot)) return true;
        if (isSubtree(root->right, subRoot)) return true;

        return false;
    }
};