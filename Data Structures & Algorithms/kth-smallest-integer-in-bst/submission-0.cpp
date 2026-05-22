class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> pq;

    int kthSmallest(TreeNode* root, int k) {
        traversal(root);

        while (k > 1) {
            pq.pop();
            k--;
        }

        return pq.top();
    }

    void traversal(TreeNode* root) {
        if (root == nullptr) return;

        traversal(root->left);
        pq.push(root->val);
        traversal(root->right);
    }
};
