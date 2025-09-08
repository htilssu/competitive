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
    int getLevel(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        return 1 + max(getLevel(node->left), getLevel(node->right));
    }


    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        if (!root) { return nullptr; }

        int leftH = getLevel(root->left);
        int rightH = getLevel(root->right);

        if (leftH == rightH) {
            return root;
        }

        if (leftH > rightH) {
            return lcaDeepestLeaves(root->left);
        }
        return lcaDeepestLeaves(root->right);
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
