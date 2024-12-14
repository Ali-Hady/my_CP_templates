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

int main() {
    Ali;
    int tc = 1;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        ll n = s.size();
        s += s;
        ll k = 0, ones = 0;
        for (auto c: s) {
            if (c == '1') k++;
            else k = 0;

            ones = max(ones, k);
        }

        if (ones > n) {
            cout << n * n << el;
            continue;
        }

        ll ans = 0, st = 2;
        for (ll i = ones - 1; i >= 1LL; --i) {
            ans = max(ans, i * st);
            ++st;
        }

        cout << max(ans, ones * 1LL) << el;
    }

    return 0;
}
