// Rolling Hash
// copy the RollingHash class.
// initiate it with StringHasher(int _prm, int _mod, string s)
// use getHash, getRevHash, isEqual, isRevEqual and isPal.

// Multi Rolling Hash
// copy the RollingHash and the MultiRollingHash class.
// hard code prm, mod and hashSize
// initiate it with MultiRollingHash(string s)
// use getHash, getRevHash, isEqual, isRevEqual and isPal.

// Random Rolling Hash
// copy the RollingHash and the MultiRollingHash and the RandomRollingHash class.
// hard code hashSize in MuliRollingHash class
// initiate it with RandomRollingHash(string s)
// use getHash, getRevHash, isEqual, isRevEqual and isPal.
// every instance has its own random hashing parameters

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class RollingHash{
public:

    static ll po(ll b, ll p, ll mod){
        b %= mod;
        p %= mod-1;
        ll r = 1;
        while(p){
            if(p&1)r = r*b%mod;
            p >>= 1;
            b = b*b%mod;
        }
        return r;
    }

    int n;
    int mod;
    int prm;
    vector<int> w;
    vector<int> _w;
    vector<int> pef;
    vector<int> suf;

    RollingHash(){}

    RollingHash(int _prm, int _mod, string s){
        prm = _prm;
        mod = _mod;
        build(s);
    }

    void build(string s){
        // initialize
        n = s.size();
        w.resize(n+2);
        _w.resize(n+2);
        pef.resize(n+2);
        suf.resize(n+2);

        // build w & _w
        w[0] = 1;
        for(int i = 1; i < w.size(); i++)w[i] = w[i-1]*1ll*prm%mod;
        _w.back() = po(w.back(), mod-2, mod);
        for(int i = w.size()-2; i >= 0; i--)_w[i] = _w[i+1]*1ll*prm%mod;

        // build pef & suf
        pef[0] = 0;
        for(int i = 0; i < n; i++){
            pef[i+1] = (pef[i] + w[i]*1ll*(s[i]-'a'+1))%mod;
        }
        suf[n] = 0;
        for(int i = n-1; i >= 0; i--){
            suf[i] = (suf[i+1] + w[n-i-1]*1ll*(s[i]-'a'+1))%mod;
        }
    }

    inline ll getHash(int l, int r){
        return (pef[r+1] + 0ll + mod - pef[l]) %mod * _w[l] %mod;
    }

    inline ll getRevHash(int l, int r){
        return (suf[l] + 0ll + mod - suf[r+1]) %mod * _w[n-r-1] %mod;
    }

    inline bool isEqual(int l1, int r1, int l2, int r2){
        return getHash(l1, r1) == getHash(l2, r2);
    }

    inline bool isRevEqual(int l1, int r1, int l2, int r2){
        return getRevHash(l1, r1) == getRevHash(l2, r2);
    }

    inline bool isPal(int l, int r){
        return getHash(l, r) == getRevHash(l, r);
    }
};


class MultiRollingHash{
public:

    static const int hashSize = 4;

    int mod[hashSize] = {(int)1e9+7, (int)1e9+7, (int)1e9+9, (int)1e9+9};
    int prm[hashSize] = {31, 37, 31, 37};
    RollingHash hashers[hashSize];

    MultiRollingHash(){}

    MultiRollingHash(string s){
        build(s);
    }

    void build(string s){
        int n = s.size();
        for(int ind = 0; ind < hashSize; ind++){
            hashers[ind] = RollingHash(prm[ind], mod[ind], s);
        }
    }
    
    vector<ll> getHash(int l, int r){
        vector<ll> ret;
        for(int ind = 0; ind < hashSize; ind++){
            ret.push_back(hashers[ind].getHash(l, r));
        }
        return ret;
    }

    vector<ll> getRevHash(int l, int r){
        vector<ll> ret;
        for(int ind = 0; ind < hashSize; ind++){
            ret.push_back(hashers[ind].getRevHash(l, r));
        }
        return ret;
    }

    bool isEqual(int l1, int r1, int l2, int r2){
        bool ret = 1;
        for(int ind = 0; ind < hashSize; ind++){
            ret &= hashers[ind].isEqual(l1, r1, l2, r2);
        }
        return ret;
    }

    bool isRevEqual(int l1, int r1, int l2, int r2){
        bool ret = 1;
        for(int ind = 0; ind < hashSize; ind++){
            ret &= hashers[ind].isRevEqual(l1, r1, l2, r2);
        }
        return ret;
    }

    bool isPal(int l, int r){
        bool ret = 1;
        for(int ind = 0; ind < hashSize; ind++){
            ret &= hashers[ind].isPal(l, r);
        }
        return ret;
    }
};


class RandomRollingHash : MultiRollingHash{
public:

    vector<int> allMods = {999999677, 999999733, 999999739, 999999751, 999999757, 999999761, 999999797,
            999999883, 999999893, 999999929, 999999937, 1000000007, 1000000009, 1000000021, 1000000033,
            1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181, 1000000207};
    vector<int> allPrms = {31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    RandomRollingHash(){}

    RandomRollingHash(string s){
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        for(int i = 0; i < hashSize; i++){
            mod[i] = allMods[uniform_int_distribution<int>(0, allMods.size()-1)(rng)];
            prm[i] = allPrms[uniform_int_distribution<int>(0, allPrms.size()-1)(rng)];
        }
        build(s);
    }
    
    vector<ll> getHash(int l, int r){
        return MultiRollingHash::getHash(l, r);
    }

    vector<ll> getRevHash(int l, int r){
        return MultiRollingHash::getRevHash(l, r);
    }

    bool isEqual(int l1, int r1, int l2, int r2){
        return MultiRollingHash::isEqual(l1, r1, l2, r2);
    }

    bool isRevEqual(int l1, int r1, int l2, int r2){
        return MultiRollingHash::isRevEqual(l1, r1, l2, r2);
    }

    bool isPal(int l, int r){
        return MultiRollingHash::isPal(l, r);
    }
};


signed main(){
    string s;
    cin >> s;
    RandomRollingHash hasher(s);
    int t;
    cin >> t;
    while(t--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--, r1--;
        l2--, r2--;
        cout << hasher.isEqual(l1, r1, l2, r2) << '\n';
    }
}