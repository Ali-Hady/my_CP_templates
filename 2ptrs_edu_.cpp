#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    Ali;
    int n, m;
    ll s, A, B;
    cin >> n >> m >> s >> A >> B;

    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    // Sort costs in descending order
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    // Handle edge case where the weight of the first element exceeds s
    if (A > s && B > s) {
        cout << 0 << el;
        return 0;
    }

    vector<ll> prefixA(n + 1, 0), prefixB(m + 1, 0);
    for (int i = 0; i < n; i++) prefixA[i + 1] = prefixA[i] + a[i];
    for (int i = 0; i < m; i++) prefixB[i + 1] = prefixB[i] + b[i];

    ll max_cost = 0;

    // Iterate over the number of Type B items
    for (int j = 0; j <= m; j++) {
        ll weightB = j * B;
        if (weightB > s) break;

        ll remaining_weight = s - weightB;
        ll maxA = remaining_weight / A;

        if (maxA > n) maxA = n;

        max_cost = max(max_cost, prefixB[j] + prefixA[maxA]);
    }

    // Iterate over the number of Type A items
    for (int i = 0; i <= n; i++) {
        ll weightA = i * A;
        if (weightA > s) break;

        ll remaining_weight = s - weightA;
        ll maxB = remaining_weight / B;

        if (maxB > m) maxB = m;

        max_cost = max(max_cost, prefixA[i] + prefixB[maxB]);
    }

    cout << max_cost << el;

    return 0;
}
