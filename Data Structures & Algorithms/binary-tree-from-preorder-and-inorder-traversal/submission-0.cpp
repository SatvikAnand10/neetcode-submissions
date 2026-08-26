class Solution {
public:
    unordered_map<int, int> pos;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Store each value's index in inorder
        for (int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int left, int right) {
        // No elements left in this subtree
        if (left > right) return nullptr;

        // Next preorder element is the root
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root's position in inorder
        int mid = pos[rootVal];

        // Build left subtree first
        root->left = build(preorder, left, mid - 1);

        // Then build right subtree
        root->right = build(preorder, mid + 1, right);

        return root;
    }
};