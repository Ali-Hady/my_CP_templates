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
#define Ali ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int MOD = 1e9 + 7;
const ll inf = 2e18 + 1;
//const int N = 1e6 + 3;

struct SegmentTree {
    vector<int> tree;
    ll identity = INT_MIN;
    int size;

    SegmentTree(int n) {
        size = n;
        ll N = 1;
        while (N < n) {
            N <<= 1;
        }

        tree.resize(N << 1);
    }

    ll merge(ll x, ll y) {
        return max(x, y);
    }

    void build(int node, int left, int right, vector<ll>& a) {
        if (left == right) {
            tree[node] = a[left];
            return;
        }

        int mid = left + right >> 1;
        build(node << 1, left, mid, a);
        build((node << 1) + 1, mid + 1, right, a);
        tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
    }

    void build(vector<ll>& a) {
        build(1, 0, size - 1, a);
    }

    void update(int node, int idx, int left, int right, int val) {
        if (left == right) {
            tree[node] = val;
            return;
        }

        int mid = left + right >> 1;
        if (mid >= idx)
            update(node << 1, idx, left, mid, val);
        else
            update(node << 1 | 1, idx, mid + 1, right, val);

        tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
    }

    void update(int idx, int val) {
        update(1, idx, 0, size - 1, val);
    }

    ll query(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return identity;
        if (start <= left && end >= right) return tree[node];

        int mid = left + right >> 1;
        ll lq = query(node << 1, start, end, left, mid);
        ll rq = query(node << 1 | 1, start, end, mid + 1, right);
        return merge(lq, rq);
    }

    ll query(int start, int end) {
        return query(1, start, end, 0, size - 1);
    }
};

int main() {
    Ali;
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        vector<ll> v = {2, 3, 1, 7, 5};
        SegmentTree seg(v.size());
        seg.build(v);
        int q;
        cin >> q;
        while (q--) {
            for (int i = 5; i <= 9; ++i) {
                cout << i << ": " << seg.tree[i] << el;
            }
        }
    }

    return 0;
}
