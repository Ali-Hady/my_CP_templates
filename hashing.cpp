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
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0)
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<tuple<ll, ll, ll>, null_type,less<tuple<ll, ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

const int MOD = 1e9 + 7;
const ll inf = 1e18;
const ll N = 6e5 + 1;

ll add(ll x, ll y) {
    return (x % MOD + y % MOD) % MOD;
}

ll subt(ll x, ll y) {
    return (((x % MOD) - (y % MOD)) % MOD + MOD) % MOD;
}

ll mult(ll x, ll y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll fp(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = mult(res, x);
        x = mult(x, x);
        y >>= 1;
    }

    return res;
}

ll inv(ll x) {
    return fp(x, MOD - 2);
}

ll divis(ll x, ll y) {
    return mult(x, inv(y));
}

int p1 = 31, p2 = 53;
int iv1 = inv(p1), iv2 = inv(p2);
pair<int, int> pw[N];
pair<int, int> invr[N];

vector<pair<int, int>> double_hash(string& s) {
    int n = s.size();
    vector<pair<int, int>> prefix_hash(n + 1);
    prefix_hash[0] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        prefix_hash[i].first = add(prefix_hash[i - 1].first, mult(s[i - 1] - 'a' + 1, pw[i - 1].first));
        prefix_hash[i].second = add(prefix_hash[i - 1].second, mult(s[i - 1] - 'a' + 1, pw[i - 1].second));
    }

    return prefix_hash;
}

int main() {
    Ali;
    pw[0] = {1, 1};
    invr[0] = {1, 1};
    for (int i = 1; i < N; ++i) { // precalc pw & inv
        pw[i] = {mult(pw[i - 1].first, p1), mult(pw[i - 1].second, p2)};
        invr[i] = {mult(iv1, invr[i - 1].first), mult(iv2, invr[i - 1].second)};
    }
}

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}