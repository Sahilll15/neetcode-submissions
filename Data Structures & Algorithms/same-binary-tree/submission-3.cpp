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
    vector<int> tree1;
    vector<int> tree2;

    bool isSameTree(TreeNode* p, TreeNode* q) {
        traversal1(p);
        traversal2(q);

        return tree1 == tree2;
    }

private:
    void traversal1(TreeNode* root){
        if(root == nullptr) {
            tree1.push_back(0);
            return;
        }

        tree1.push_back(root->val);
        traversal1(root->left);
        traversal1(root->right);
    }

    void traversal2(TreeNode* root){
        if(root == nullptr) {
            tree2.push_back(0);
            return;
        }

        tree2.push_back(root->val);
        traversal2(root->left);
        traversal2(root->right);
    }
};
