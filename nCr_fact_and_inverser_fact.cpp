#include <bits/stdc++.h>

const int N = 2000007;

const int mod = 1000000007;

int fact[N], ifact[N];

int pow(int a, int b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * 1ll * a % mod;
        b >>= 1;
    }
    return res;
}

void f() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * 1ll * i % mod;
        ifact[i] = ifact[i - 1] * 1ll * pow(i, mod - 2) % mod;
    }
}

int c(int n, int r) {
    if (r < 0 || n < r) return 0;
    return fact[n] * 1ll * ifact[r] % mod * ifact[n - r] % mod;
}

signed main() {
    f();
return 0;
}
