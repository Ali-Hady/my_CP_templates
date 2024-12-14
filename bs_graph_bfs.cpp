#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m, d;
vector<vector<pair<int, int>>> edges;

//int mn = INT_MAX;
vector<int> ans;

bool good(int mid) {
    //int mx = 0;
    vector<bool> vis(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &ch: edges[cur]) {
            if (!vis[ch.first] && ch.second < mid) {
                vis[ch.first] = true;
                //mx = max(mx, ch.second);
                parent[ch.first] = cur;
                q.push(ch.first);
            }
        }
    }

    if (parent[n - 1] == -1)
        return false;

    ans.clear();
    int cur = n - 1; // backtrack
    while (cur != -1) {
        ans.push_back(cur);
        cur = parent[cur];
    }

    if (ans.size() - 1 <= d) {
        return true;
    }

    return false;
}

int main() {
    Ali;
    cin >> n >> m >> d;
    edges.resize(n);
    int mx = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        edges[u].push_back({v, c});
        mx = max(mx, c);
    }

    int l = 0, r = mx + 1, mid;

    while (r > l + 1) {
        mid = (l + r) / 2;
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
