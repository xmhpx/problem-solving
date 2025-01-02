struct BIT {
    const static int SIZE = 1e6+7;
    array<ll, SIZE> tr;
    BIT() { tr.fill(0); }
    inline void Update(int x, const ll& v) {
        for(; x < SIZE; x += (x & -x)) tr[x] += v;
    }
    inline ll Query(int x) {
        ll ans = 0;
        for(; x; x -= (x & -x)) ans += tr[x];
        return ans;
    }
};