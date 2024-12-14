#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define ll long long
#define inf 1e18
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

bool good(ll m, ll arr[], int n, int k) {
    ll cnt = 1; // Place the first cow in the first stall
    ll last_position = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - last_position >= m) {
            cnt++;
            last_position = arr[i];
        }
        if (cnt >= k) return true;
    }

    return cnt >= k;
}

int main() {
    Ali;
    int n, k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll l = 0, r = 1e9, m;
    while (r > l + 1) {
        m = (l + r) / 2;
        if (good(m, arr, n, k))
            l = m;
        else
            r = m;
    }

    cout << l << el;

    return 0;
}
