#include <iostream>
#include <ostream>
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

class Solution {
public:
    int sumNodes(int current, TreeNode *root) {
        if (root == nullptr) {
            return current;
        }

        const int value = current * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return value;
        }

        if (root->left != nullptr && root->right == nullptr) {
            return sumNodes(value, root->left);
        }
        if (root->left == nullptr) {
            return sumNodes(value, root->right);
        }

        return sumNodes(value, root->left) + sumNodes(value, root->right);
    }

    int sumNumbers(TreeNode *root) {
        return sumNodes(0, root);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << Solution().sumNumbers(root) << endl;
}
