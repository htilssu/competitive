#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long


class Solution {
public:
    long long minimalKSum(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        ll sum = (ll)k * (k + 1) / 2;

        for (int i : nums) {
            if (i <= k) {
                k++;
                sum += k - i;
            } else {
                break;
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector nums{
        96, 44, 99, 25, 61, 84, 88, 18, 19, 33, 60, 86, 52, 19, 32, 47, 35, 50, 94, 17, 29, 98, 22, 21, 72, 100, 40, 84
    };
    cout << sol.minimalKSum(nums, 35) << endl;
    //794
    return 0;
}
