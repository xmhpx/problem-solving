// template.cpp
// use inp.txt/out.txt for file IO
/*
Pragma:
If ever in doubt about whether your pragmas are correct,
turn on most compiler warnings with the command-line option -Wall(or the more specific -Wunknown-pragmas). 
use assert(__builtin_cpu_supports("avx2")) to check if intruction set is available
*/

// #pragma GCC optimize ("O2,unroll-loops")
// #pragma GCC optimize("no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("O3","unroll-loops")
// #pragma GCC optimize ("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("sse4") // instead of avx2
// __attribute__((target("avx2"), optimize("O3", "unroll-loops")))

#include <bits/stdc++.h>

#define oo (1000'000'000'000'000'000LL)
#define cif(i, n) for(int i = 0; i < n; i++)
#define ccif(i, l, r) for(int i = l; i < r; i++)
#define rif(i, n) for(int i = n-1; i >= 0; i--)
#define rrif(i, l, r) for(int i = r-1; i >= l; i--)
#define scan(a, __n) {for(int __ = 0; __ < __n; __++)cin >> a[__];}
#define print(a, __n) {for(int __ = 0; __ < __n; __++)cout << a[__] << ' '; cout << '\n';}
#define sz(s) ((int)s.size())
#define dbg(x) cerr << #x << " : " << x << endl;
#define rep(i, l, r) for(int i = l; i < r; i++)
// #define mset(a, chr) memset(a, chr, sizeof a)
#define mset(a) memset(a, 0, sizeof a)
//  #define int ll

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#define ff first
#define ss second

#define all(v) v.begin(), v.end()
#define uni(v) sort(all(v)), v.resize(unique(all(v))-v.begin());

// #define c0 (v<<1)
// #define c1 (c0|1)
// #define md ((l+r)/2)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ld> vd;
typedef pair<ld, ld> pt;
typedef vector<pt> vpt;


const int mod = 1e9+7;

// const string fileName = "";

// const int maxFac = 1e6+7; 
// ll fac[maxFac], _fac[maxFac];

// ll po(ll b, ll p){
//     b %= mod;
//     p %= mod-1;
//     ll r = 1;
//     while(p){
//         if(p&1)r = r*b%mod;
//         p >>= 1;
//         b = b*b%mod;
//     }
//     return r;
// }

// ll choose(ll k, ll n){
//     return fac[n]*_fac[k]%mod*_fac[n-k]%mod;
// }

// ll factorial(ll n, ll k){
//     ll ret = 1;
//     for(ll i = n; i >= n-k+1; i--){
//         ret = ret*i%mod;
//     }
//     return ret;
// }

const int maxN = 1e6+7;

inline void slv(){

}

/*

*/

inline void prep(){
    
    // fac[0] = 1;
    // for(int i = 1; i < maxFac; i++)fac[i] = fac[i-1]*i%mod;
    // _fac[maxFac-1] = po(fac[maxFac-1], mod-2);
    // for(int i = maxFac-2; i >= 0; i--)_fac[i] = _fac[i+1]*(i+1)%mod;

    // w[0] = 1;
    // for(int i = 1; i < maxN; i++)w[i] = w[i-1]*p%mod;
    // _w[maxN-1] = po(w[maxN-1], mod-2);
    // for(int i = maxN-2; i >= 0; i--)_w[i] = _w[i+1]*p%mod;
    
    // for(int i = 2; i < maxN; i++){
    //     if(lp[i] == 0){
    //         lp[i] = i;
    //         pr.push_back(i);
    //     }
    //     for (int j = 0; i * pr[j] < maxN; ++j) {
    //         lp[i * pr[j]] = pr[j];
    //         if (pr[j] == lp[i]) {
    //             break;
    //         }
    //     }
    // }
}

signed main(){
    // if(fileName.size() > 0){
        // freopen("inp.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    // }

    fastIO;

    // cout << fixed << setprecision (15);

    prep();
    
    int t = 1;
    // cin >> t;
    while(t--){
        // cout << slv() << '\n';
        slv();
        // string s;
        // cin >> s;
        // bool x = slv();
        // cout << (x?"YES":"NO") << '\n';
    }
}

/*

*/