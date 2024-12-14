//
// Created by ali on 10/26/2024.
//
#include <cctype>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>
#include <set>
#include<cmath>
#include <cstring>
#include <numeric>
#include <tuple>
#include <queue>
#include <stack>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int MOD = 1e9 + 7;
const ll inf = 2e18 + 1;
const int N = 1e6 + 3;

int main() {
    Ali;
    int tc = 1;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        map<ll, vector<ll>> edges;
        for (int i = 0; i < n; ++i) {
            ll u = v[i] + (ll)i;
            ll v = u + (ll)i;
            edges[u].push_back(v);
        }

        set<ll> vis;
        function<void(ll)> dfs = [&] (ll u) {
            if (vis.count(u)) return ;
            vis.insert(u);
            for (auto ch: edges[u])
                dfs(ch);
        };

        dfs(n);

        cout << *vis.rbegin() << el;
    }

    return 0;
}




