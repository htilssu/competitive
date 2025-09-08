#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};


using namespace std;

class Solution {
public:
    int maxLevel = 0;
    int minRoot = INT_MAX;

    int getLevel(TreeNode *node) {
        if (node == nullptr) {
            return -1;
        }


        int leftLevel = 1 + getLevel(node->left);
        int rightLevel = 1 + getLevel(node->right);

        return max(leftLevel, rightLevel);
    }

    TreeNode *calTreeLevel(TreeNode *node, int level) {
        if (node->left == nullptr && node->right == nullptr) {
            if (level < maxLevel) {
                return nullptr;
            }
            return node;
        }

        TreeNode *left = nullptr;
        TreeNode *right = nullptr;

        if (node->left != nullptr) {
            left = calTreeLevel(node->left, level + 1);
        }

        if (node->right != nullptr) {
            right = calTreeLevel(node->right, level + 1);
        }

        if (left == nullptr && right == nullptr) {
            return nullptr;
        }

        TreeNode *minV;
        if (left != nullptr && right != nullptr) {
            return node;
        }
        if (left != nullptr) {
            minV = left;
        } else {
            minV = right;
        }


        return minV;
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        maxLevel = getLevel(root);
        return calTreeLevel(root, 0);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    cout << s.lcaDeepestLeaves(root)->val;
}
