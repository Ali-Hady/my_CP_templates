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
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<tuple<ll, ll, ll>, null_type,less<tuple<ll, ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

const int MOD = 1e9 + 7;
const ll inf = 1e18;
const ll N = 1e5 + 1;

int main() {
    Ali;
    ll t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n];
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }

        cout << 0 << " ";
        int y_prev = 0;
        for (int i = 1; i < n; ++i) {
            int y = 0;
            for (int j = 0; j < 30; ++j) {
                int a = ((x[i - 1] ^ y_prev) >> j) & 1;
                int b = (x[i] >> j) & 1;
                if (a == 1 && b == 0) {
                    y |= (1 << j);
                }
            }

            cout << y << " ";
            y_prev = y;
        }

        cout << el;
    }

    return 0;
}