#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    Ali;
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    map<ll, int> dp;
    int maxLength = 0;
    ll endValue = -1;

    for (int i = 0; i < n; ++i) {
        dp[arr[i]] = dp[arr[i] - 1] + 1;

        if (dp[arr[i]] > maxLength) {
            maxLength = dp[arr[i]];
            endValue = arr[i];
        }
    }

    if (maxLength == 0) {
        cout << 0 << el;
        return 0;
    }

    vector<int> indices;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] == endValue) {
            indices.push_back(i + 1);
            endValue--;
        }

    }

    reverse(indices.begin(), indices.end());

    cout << maxLength << el;
    for (auto idx : indices) {
        cout << idx << " ";
    }
    cout << el;

    return 0;
}
