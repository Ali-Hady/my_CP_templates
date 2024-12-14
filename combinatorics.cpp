#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define inf 1e18
#define wedges vector<vector<pair<ll, ll>>> wedges
#define wpq priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> wpq
using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {
    return (a%mod + b%mod)%mod;
}

int mult(long long a, int b) {
    return ((a%mod)*(b%mod))%mod;
}

int subt(int a, int b) {
    return (((a%mod)-(b%mod))%mod + mod)%mod;
}

int fp(int a, int b) { // Binary Exponentiation
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mult(res, a); // compute only when cur bit is on

        a = mult(a, a);
        b >>= 1; // move to next bit
    }

    return res;
}

int inv(int a) {
    return fp(a, mod-2);
}

int divi(int a, int b) {
    return mult(a, inv(b));
}

int fact[N];


int nPr(int n, int r) {
    if(r > n) return 0;
    if(n < 0 || r < 0) return 0;
    return divi(fact[n], fact[n-r]);
}

int nCr(int n, int r) {
    if(r > n) return 0;
    if(n < 0 || r < 0) return 0;
    return divi(fact[n], mult(fact[r], fact[n-r]));
}

int sNb(int n, int k) {
    return nCr(n+k-1, n);
}

void precalFactorial() {
    fact[0] = 1;

    for(int i =1 ; i < N; i++)
        fact[i] = mult(fact[i-1], i);
}
