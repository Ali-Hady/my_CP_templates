#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
#define el '\n'
#define inf 1e18
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int MOD = 998244353;

ll get(int l, int r) {
    if (l == r || (l == 0 || l == 1) && (r == 2 || r == 3))
        return 0;
    if ((l == 2 && r == 3) || (l == 3 && r == 2))
        return 2;

    return 1;
}

int main() {
    Ali;
    int n, k;
    cin >> n >> k;

    ll dp[n][k + 1][4] {};
    // 0 - > WW, 1 -> BB, 2 -> WB, 3 -> BW
    dp[0][1][0] = dp[0][1][1] = dp[0][2][2] = dp[0][2][3] = 1;

    for (int i = 0; i < n - 1; ++i) {
        for (ll j = 1; j <= k; ++j) {
            for (int l = 0; l < 4; ++l) {
                for (int r = 0; r < 4; ++r) {
                    ll nc = get(l, r);
                    if (j + nc > k) continue;
                    dp[i + 1][j + nc][l] = (dp[i + 1][j + nc][l] + dp[i][j][r]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int way = 0; way < 4; ++way) {
        ans = (ans + dp[n-1][k][way]) % MOD;
    }

    cout << ans << el;
}