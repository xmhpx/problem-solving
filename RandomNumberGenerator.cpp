// Random Number Generator
// copy the RandomNumberGenerator class.
// use shuffle to shuffle a vector (you can use rng to shuffle using random access iterators instead).
// use next and wnext for uniform random long long and weighted random long long.
// based on this wonderfull blog https://codeforces.com/blog/entry/61587

#include <bits/stdc++.h>

using namespace std;

class RandomNumberGenerator{
public:
    mt19937 rng;
    RandomNumberGenerator(){
        rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    }

    void shuffle(vector<int> &p){
        ::shuffle(p.begin(), p.end(), rng);
    }

    long long next(long long a, long long b){
        assert(a <= b);
        if(a == b)return a;
        return uniform_int_distribution<long long>(a, b)(rng);
    }

    long long wnext(long long a, long long b, int w){
        if(w == 0)return next(a, b);
        if(w < 0){
            return min(wnext(a, b, w+1), next(a, b));
        }
        else{
            return max(wnext(a, b, w-1), next(a, b));
        }
    }
};

int main() {
    RandomNumberGenerator rng;
    cout << rng.wnext(1, 10, 2) << '\n';
}