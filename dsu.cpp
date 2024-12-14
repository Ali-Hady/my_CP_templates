#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 150000 + 5;

vector<vector<ll>> edges(N);
ll labels[N]; // label of every vertex in the same component
ll nedges[N]; // nedges for every label (component)
ll sz[N]; // size of every labeled component

void relabel(ll start, ll target) {
    stack<ll> s;
    s.push(start);

    while (!s.empty()) {
        ll u = s.top();
        s.pop();

        if (labels[u] == target) continue;
        labels[u] = target;

        for (auto ch : edges[u]) {
            if (labels[ch] != target) {
                s.push(ch);
            }
        }
    }
}

void merge(ll u, ll v) {
    edges[u].push_back(v);
    edges[v].push_back(u);

    ll lu = labels[u], lv = labels[v];
    nedges[lu]++;

    if (lu == lv) return;

    // Always merge the smaller component into the larger one
    if (sz[lu] > sz[lv]) {
        swap(u, v);
        swap(lu, lv);
    }

    relabel(u, lv);

    nedges[lv] += nedges[lu]; // add new edges to component lv
    sz[lv] += sz[lu]; // expand size
}

int main() {
    Ali;

    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < n; ++i) {
        sz[i] = 1;
        labels[i] = i;
    }

    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        merge(u, v);
    }

    bool yes = 1;
    for (ll i = 0; i < n; ++i) {
        if (nedges[labels[i]] != sz[labels[i]] * (sz[labels[i]] - 1) / 2) {
            yes = 0;
            break;
        }
    }

    if (yes)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
