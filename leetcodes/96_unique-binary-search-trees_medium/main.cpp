#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dp = vector(20, 0);

    int countChild(int n) {
        if (n <= 1) return 1;
        if (dp[n] == 0) {
            int count = 0;
            int left = 0;
            const int remain_node = n - 1;
            while (left <= remain_node) {
                int l_count = countChild(left);
                int r_count = countChild(remain_node - left);
                count += l_count * r_count;

                left++;
            }

            dp[n] = count;
        }
        return dp[n];
    }

    int numTrees(int n) {
        if (n == 1) return 1;
        dp[2] = 2;


        return countChild(n);
    }
};

int main() {
    Solution s;
    cout << s.numTrees(6) << endl;
    return 0;
}
