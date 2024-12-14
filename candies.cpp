#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <string>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define inf 1e18
using namespace std;

const int MOD = 1e9+7;

int main() {
    Ali;
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll dp[n + 1][k + 1] {};
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        ll prefix[k + 1] {};
        prefix[0] = dp[i - 1][0];
        for (int j = 1; j <= k; ++j) {
            prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % MOD;
            // sum all posible k candies for prev children
        }

        for (int j = 0; j <= k; ++j) {
            int mx = min(j * 1LL, arr[i - 1]); // mx allowed candies for current child
            dp[i][j] = prefix[j]; // we are interested in j candies
            if (j - mx - 1 >= 0)
                dp[i][j] = (prefix[j] - prefix[j - mx - 1] + MOD) % MOD;
        }
    }

    cout << dp[n][k] << el;

    return 0;
}
