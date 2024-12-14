#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>
#include <set>
#include<cmath>
#include <cstring>
#include <numeric>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int MOD = 998244353;
const ll inf = 1e18;
const ll N = 1e7 + 3;

int main() {
    Ali;
    ll n, q;
    cin >> n;
    ll arr[n];
    ll g = 0;
    for (ll &i: arr) {
        cin >> i;
        g = gcd(g, i);
    }

    vector<ll> divs;

    for (ll i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            divs.push_back(i);
            if (g / i != i)
                divs.push_back(g / i);
        }
    }

    sort(divs.begin(), divs.end());
    int prefix[62][n + 1]; // count of ith bit set for jth number; j < n
    for (int i = 0; i < 62; ++i) {
        prefix[i][0] = 0;
        prefix[i][1] = ((arr[0] >> i) & 1); // check if ith bit is set
        for (int j = 2; j <= n; ++j) {
            prefix[i][j] = ((arr[j - 1] >> i) & 1) + prefix[i][j - 1];
        }
    }

    cin >> q;
    ll l, r;
    while (q--) {
        cin >> l >> r;
        if (l > divs.size() || r > divs.size()) {
            cout << -1 << el;
            continue;
        }

        --l, --r;
        cout << divs[l] << " " << divs[r] << el;
        l = min(divs[l], n);
        r = min(divs[r], n);

        ll ans = 0;
        for (int i = 0; i < 62; ++i) {
            int x = prefix[i][r] - prefix[i][l - 1];

            if (x == r - l + 1) // ith bit is set up in entire range
                ans |= (1LL << i); // light up ith bit
        }

        cout << ans << el;
    }

    return 0;
}