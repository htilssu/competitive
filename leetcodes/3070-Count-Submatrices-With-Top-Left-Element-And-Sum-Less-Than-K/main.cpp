#include <bits/stdc++.h>
using namespace std;

// ----------- Fast IO -----------
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

// ----------- Aliases -----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;

// ----------- Macros -----------
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())

// Loop macros
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) for (int i = 0; i < (n); i++)

// Debug macro (bật khi biên dịch với -DLOCAL)
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << "\n"
#else
#define debug(x)
#endif

// ----------- Solution class (LeetCode style) -----------
class Solution {
public:
    vector<vector<int> > dp;

    int countSubmatrices(vector<vector<int> > &grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        dp.assign(n, vector<int>(m, -1));

        int count = 0;
        int maxj = grid[0].size();

        FOR(i, 0, grid.size()) {
            if (i == 0) {
                dp[i][i] = grid[i][i];
            }
            FOR(j, 0, maxj) {
                if (dp[i][j] == -1) {
                    if (i > 0 && j > 0) {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i][j];
                    } else if (i == 0 && j > 0) {
                        dp[i][j] = dp[i][j - 1] + grid[i][j];
                    } else if (j == 0 && i > 0) {
                        dp[i][j] = dp[i - 1][j] + grid[i][j];
                    }

                }
                if (dp[i][j] > k) {
                    maxj = j;
                } else {
                    count++;
                }
            }
        }

        return count;
    }
};

// ----------- Main for local test -----------
int main() {
    Solution sol;
    vector<vector<int> > grid = {{7, 6, 3}, {6, 6, 1}};
    int k = 18;

    int ans = sol.countSubmatrices(grid, k);

    cout << "Result = " << ans << endl;
    return 0;
}
