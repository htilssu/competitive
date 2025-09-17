#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numWays(string s) {
        vector<int> mark;
        const long long MOD = 10e9 + 7;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                mark.push_back(i);
            }
        }
        if (mark.size() % 3 != 0) {
            return 0;
        }
        if (mark.empty()) {
            return ((s.size() - 1) * (s.size() - 2) / 2) % MOD;
        }
        int avg = mark.size() / 3;
        int i = mark[avg - 1];
        int j = mark[avg];
        int o = mark[avg * 2 - 1];
        int k = mark[avg * 2];

        return (j - i) * (k - o) % MOD;
    }
};

int main() {
    Solution s;
    cout << s.numWays("100100010100110") << endl;
    return 0;
}
