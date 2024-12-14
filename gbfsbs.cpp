#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m;
vector<vector<pair<int, double>>> edges;

//int mn = INT_MAX;
vector<int> ans;

bool good(double mid) {
    vector<bool> vis(n, false);
    vector<int> parent(n, -1);
    vector<double> prefix(n, numeric_limits<double>::max()); // Start with large values
    queue<int> q;
    q.push(0);
    vis[0] = true;
    prefix[0] = 0; // Start prefix at 0 for the first node

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &ch : edges[cur]) {
            double newPrefix = ch.second + prefix[cur] - mid;

            // Only update if the new prefix is better (smaller)
            if (newPrefix < prefix[ch.first]) {
                vis[ch.first] = true;
                parent[ch.first] = cur;
                prefix[ch.first] = newPrefix;
                q.push(ch.first);
            }
        }
    }

    if (parent[n - 1] == -1 || prefix[n - 1] > 0)
        return false;

    // Backtrack the path
    ans.clear();
    int cur = n - 1;
    while (cur != -1) {
        ans.push_back(cur);
        cur = parent[cur];
    }

    return true;
}


int main() {
    Ali;
    cin >> n >> m;
    edges.resize(n);
    double mx = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        double c;
        cin >> u >> v >> c;
        --u, --v;
        edges[u].push_back({v, c});
        mx = max(mx, c);
    }

    double l = 0.0, r = mx + 1, mid;

    for (ll i = 0; i < 100; ++i) {
        mid = (l + r) / 2.0;
        if (good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    if (good(r)) {
        cout << ans.size() - 1 << el;
        for (int i = ans.size() - 1; i >= 0; --i)
            cout << ans[i] + 1 << " ";
    } else
        cout << -1 << el;

    return 0;
}
