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
    vector<int> bfs(TreeNode* root) {
    vector<int> vec;
    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        vec.push_back(node->val);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return vec;
}

    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec=bfs(root);
        priority_queue<int> pq;
        for(auto a:vec){
            pq.push(a);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
