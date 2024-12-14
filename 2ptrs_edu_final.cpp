#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
// new insight unlocked

int n, s;
struct super_stack {
    vector<int> s;
    vector<bitset<1003>> sfnd_rcrd; // stack of bitset dps, isn't that cool!!

    void init() {
        bitset<1003> dp;
        dp[0] = 1; // a sum of zero always achievable
        sfnd_rcrd.push_back(dp);
    }

    void push(int e) {
        bitset<1003> dp = sfnd_rcrd.back();
        s.push_back(e);
        sfnd_rcrd.push_back(dp | (dp << e)); // new sums achievable
    }

    int pop() {
        int ans = s.back();
        s.pop_back();
        sfnd_rcrd.pop_back();
        return ans;
    }

    bool empty() {
        return s.empty();
    }

    bitset<1003> eval() {
        return sfnd_rcrd.back();
    }
};

super_stack s1, s2;

void add(int e) {
    s2.push(e);
}

void remove() {
    if (s1.empty())
        while (!s2.empty())
            s1.push(s2.pop());

    s1.pop();
}

bool good() {
    bitset<1003> dp1 = s1.eval();
    bitset<1003> dp2 = s2.eval();

    for (int i = 0; i <= s; i++) {
        if (dp1[i] && dp2[s - i]) // our total sum exists accross our two stacks (or one of them)
            return 1;
    }

    return false;
}

int main() {
    Ali;
    s1.init(), s2.init();
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 1e9, l = 0;
    for (int r = 0; r < n; r++) {
        add(arr[r]);

        while (good()) {
            ans = min(ans, r - l + 1);
            remove();
            l++;
        }
    }

    if (ans == 1e9)
        cout << -1 << el;
    else
        cout << ans << el;

    return 0;
}
