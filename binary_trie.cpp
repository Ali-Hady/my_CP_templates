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
#define Ali ios_base::sync_with_stdio(0); cin.tie(0)
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<tuple<ll, ll, ll>, null_type,less<tuple<ll, ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

const int MOD = 1e9 + 7;
const ll inf = 1e18;
const ll N = 2e5 + 1;

const int k = 2;
const int BIN = 64;

struct Node {
    int next[k];
    bool output = false;
    int count = 0;

    Node() {
        fill(begin(next), end(next), -1);
    }
};

void add_num(ll num, vector<Node>& bin_trie) {
    int v = 0;
    for (int i = BIN - 1; i >= 0; --i) {
        int idx = (num >> i) & 1;
        if (bin_trie[v].next[idx] == -1) {
            bin_trie[v].next[idx] = bin_trie.size();
            bin_trie.emplace_back();
        }

        v = bin_trie[v].next[idx];
        bin_trie[v].count++;
        //cout << idx << el;
    }

    bin_trie[v].output = true;
}

void remove_num(ll num, vector<Node>& bin_trie) {
    int v = 0;
    for (int i = BIN - 1; i >= 0; --i) {
        int idx = (num >> i) & 1;
        v = bin_trie[v].next[idx];
        bin_trie[v].count--;
    }

    bin_trie[v].output = false;
}

ll query(ll num, vector<Node>& bin_trie) {
    int v = 0;
    ll ans = 0;
    for (int i = BIN - 1; i >= 0; --i) {
        int bit = (num >> i) & 1;
        int nxt = bin_trie[v].next[bit ^ 1];
        if (nxt != -1 && bin_trie[nxt].count > 0) {
            bit ^= 1;
        }

        ans |= ((ll)bit << (i));
        v = bin_trie[v].next[bit];
    }

    return ans;
}

int main() {
    Ali;
    vector<Node> bin_trie(1);
    int q;
    cin >> q;
    add_num(0, bin_trie);
    while(q--) {
        char op; ll num;
        cin >> op >> num;
        if (op == '+')
            add_num(num, bin_trie);
        else if (op == '-')
            remove_num(num, bin_trie);
        else {
            cout << (query(num, bin_trie) ^ num) << el;
        }
    }

    return 0;
}