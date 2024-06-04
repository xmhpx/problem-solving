// FastMode
// copy the FastMode class.
// instantiate a FastMode with b = mod.
// use reduce function to calculate a module b.

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}

	// return a mod b
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};
FastMod F(2);

int main() {
	int M = 1000000007; F = FastMod(M);
	ull x = 10ULL*M+3; 
	cout << x << " " << F.reduce(x) << "\n"; // 10000000073 3
}