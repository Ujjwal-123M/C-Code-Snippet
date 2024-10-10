#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pool(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define um unordered_map
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) a.size()
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pi;

const int MOD = 1e9 + 7;

struct Mint {
    int val;
    Mint(ll v = 0) { 
        val = int(v % MOD);
        if (val < 0) val += MOD;
    }
    
    Mint operator + (const Mint& other) const {
        return Mint(val + other.val);
    }
    
    Mint operator - (const Mint& other) const {
        return Mint(val - other.val);
    }
    
    Mint operator * (const Mint& other) const {
        return Mint(1LL * val * other.val);
    }
    
    Mint pow(ll p) const {
        Mint result = 1, base = *this;
        while (p) {
            if (p & 1) result = result * base;
            base = base * base;
            p >>= 1;
        }
        return result;
    }
    
    Mint inv() const {
        return pow(MOD - 2); // Fermat's little theorem
    }
    
    Mint operator / (const Mint& other) const {
        return *this * other.inv();
    }
};

vi fact, invFact;

void precomputeFactorials(int n) {
    fact = vi(n + 1);
    invFact = vi(n + 1);
    fact[0] = invFact[0] = 1;
    loop(i,1,n+1) {
        fact[i] = Mint(fact[i-1]) * Mint(i);
    }
    invFact[n] = Mint(1) / Mint(fact[n]);
    pool(i,n-1,1) {
        invFact[i] = Mint(invFact[i+1]) * Mint(i+1);
    }
}

Mint nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return Mint(fact[n]) * Mint(invFact[r]) * Mint(invFact[n - r]);
}

int main() {
    int n = 10, r = 3;
    precomputeFactorials(n);
    Mint result = nCr(n, r);
    // Output the result
    return 0;
}
