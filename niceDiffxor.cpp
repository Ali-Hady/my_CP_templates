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
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int MOD = 1e9 + 7;
const ll inf = 2e18 + 1;
const int N = 1e5 + 3;
ll prefix[34][N] {};
ll ps[N] {};
ll diff[34][N] {};

ll ss(int l, int r) {
    ll sum = 0;
    for (int i = 0; i < 34; ++i) {
        sum += (prefix[i][r] - prefix[i][l - 1]) * (1LL << i);
    }
    return sum;
}

ll xx(int l, int r) {
    ll res = 0;
    for (int i = 0; i < 34; ++i) {
        res |= ((prefix[i][r] - prefix[i][l - 1]) & 1) << i;
    }
    return res;
}

int main() {
    Ali;
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n;

        ll arr[n + 1];
        ll temp[n + 1] {};
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        cin >> q;

        bool wt = 1;
        while (q--) {
            int tp;
            cin >> tp;
            if (tp == 1) {
                int l, r;
                ll k;
                cin >> l >> r >> k;
                for (int i = 0; i < 34; ++i) {
                    if ((1LL << i) & k) {
                        diff[i][l] ^= 1;
                        if (r + 1 <= n) {
                            diff[i][r + 1] ^= 1;
                        }
                    }
                }
            }
            else {
                if (wt) {
                    for (int i = 0; i < 34; ++i) {
                        for (int j = 1; j <= n; ++j) {
                            diff[i][j] ^= diff[i][j - 1];
                            if (diff[i][j] & 1) arr[j] ^= (1LL << i);
                        }
                    }

                    for (int i = 0; i < 34; ++i) {
                        prefix[i][0] = 0;
                        for (int j = 1; j <= n; ++j) {
                            prefix[i][j] = ((arr[j] >> i) & 1) + prefix[i][j - 1];
                        }
                    }

                    wt = 0;
                }

                int l, r;
                cin >> l >> r;

                if (tp == 2) {
                    cout << xx(l, r) << el;
                }
                else {
                    cout << ss(l, r) << el;
                }
            }
        }

        //for (int i = 1; i <=n ; ++i) cout << arr[i] << " ";
    }

    return 0;
}
