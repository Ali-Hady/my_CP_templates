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
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<tuple<ll, ll, ll>, null_type,less<tuple<ll, ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

const int MOD = 1e9 + 7;
const ll inf = 1e18;
const ll N = 6e5 + 1;
const int k = 26;

struct Node {
    int next[k];
    bool output = false;
    int count = 0;

    Node() {
        fill(begin(next), end(next), -1);
    }
};

void add_string(string &s, vector<Node>& trie) {
    int v = 0;
    for (auto c: s) {
        if (trie[v].next[c - 'a'] == -1) {
            trie[v].next[c - 'a'] = trie.size();
            trie[v].count++;
            trie.emplace_back();
        }

        v = trie[v].next[c - 'a'];
    }

    trie[v].output = true; // complete word formed at node v
}

void remove_string(string &s, vector<Node>& trie) {
    int v = 0;

    vector<int> nodes(1, 0);
    for (auto c: s) {
        if (trie[v].next[c - 'a'] == -1) {
            return;
        }

        nodes.push_back(v); // Save current node
        v = trie[v].next[c - 'a'];
    }

    trie[v].output = false; // complete word formed at node v
}

bool find(string& s, vector<Node>& trie) {
    int v = 0;
    for (auto c: s) {
        if (trie[v].next[c - 'a'] == -1) {
            return false;
        }

        v = trie[v].next[c - 'a'];
    }

    return trie[v].output;
}

int main() {
    Ali;
    vector<Node> trie(1); // trie with root
    string s = "abc";
    add_string(s, trie);
    if (find(s, trie))
        cout << "YES\n";
    else
        cout << "NO\n";

    remove_string(s, trie);
    if (find(s, trie))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}