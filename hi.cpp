#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int MOD = 1e9 + 7;

int main() {
    Ali;
    int n;
    int abc[3];
    cin >> n;
    for (int i = 0; i < 3; i++)
        cin >> abc[i];

    ll dp[n + 1];

    for (int i = 0; i < n + 1; i++)
        dp[i] = -1;

    dp[0] = 0;

    for (int i = 0; i <= n; i++) {
        if (dp[i] == -1) continue;
        for (auto cu: abc)
            if (cu + i < n + 1)
                dp[i + cu] = max(dp[i + cu], 1 + dp[i]);
    }

    cout << dp[n] << el;

    return 0;
}