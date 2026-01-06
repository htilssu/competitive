#include <map>
#include <queue>
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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        std::queue<TreeNode*> q;
        q.push(root);

        int max_sum = -2e9;
        int best_level = 1;
        int current_level = 1;

        while (!q.empty()) {
            int nodes_at_current_level = q.size();
            long long level_sum = 0;
            for (int i = 0; i < nodes_at_current_level; i++) {
                TreeNode* node = q.front();
                q.pop();

                level_sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (level_sum > max_sum) {
                max_sum = level_sum;
                best_level = current_level;
            }
            current_level++;
        }

        return best_level;
    }
};
