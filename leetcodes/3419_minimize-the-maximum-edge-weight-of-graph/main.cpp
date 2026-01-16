#include <algorithm>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    bool canReachAll(int n, int maxW, const vector<vector<pair<int, int> > > &adj) {
        vector<bool> visited(n, false);

        queue<int> q;
        visited[0] = true;
        int count = 1;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            auto d = adj[v];
            for (const auto pair: d) {
                int u = pair.first;
                int w = pair.second;

                if (!visited[u] && w <= maxW) {
                    visited[u] = true;
                    count++;
                    q.push(u);
                }
            }
        }

        return count == n;
    }

    int minMaxWeight(int n, vector<vector<int> > &edges, int threshold) {
        vector<vector<pair<int, int> > > adj(n);
        vector<int> weights(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            weights.push_back(w);
            adj[v].push_back(make_pair(u, w));
        }
        ranges::sort(weights);

        int left = 0;
        int right = weights.size() - 1;
        int maxV = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReachAll(n, weights[mid], adj)) {
                maxV = min(maxV, weights[mid]);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return maxV == INT_MAX ? -1 : maxV;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<vector<int> > edges;
    //[[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]]
    edges.push_back(vector<int>{1, 0, 1});
    edges.push_back(vector<int>{2, 0, 2});
    edges.push_back(vector<int>{3, 0, 1});
    edges.push_back(vector<int>{4, 3, 1});
    edges.push_back(vector<int>{2, 1, 1});
    const int result = sol.minMaxWeight(5, edges, 2);
    cout << result << endl;
}
