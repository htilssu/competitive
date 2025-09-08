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
    int dp[3501];
    map<string, int> mp;

    int numberOfCombinations(string num) {
        if (num[0] == '0') {
            return 0;
        }

        FOR(i, 0, sz(num)) {
            dp[i] = num[i] - '0';
        }


    }
};

// ----------- Main for local test -----------
int main() {
    FAST_IO
    Solution sol;

    int result = sol.numberOfCombinations(string("934459"));
    cout << result << endl;
    // result = 3;
    return 0;
}
