// TODO

#include <bits/stdc++.h>

using namespace std;

class MaxSegTree {
  private:
	int len;
	vector<int> segtree;

  public:
	MaxSegTree(int len) : len(len), segtree(2 * len) {}

	void set(int ind, int val) {
		for (segtree[ind += len] = val; ind > 1; ind >>= 1) {
			segtree[ind >> 1] = max(segtree[ind], segtree[ind ^ 1]);
		}
	}

	// maximum of the range [from, to)
	int range_max(int from, int to) {
		int max_ = INT32_MIN;
		for (from += len, to += len; from < to; from >>= 1, to >>= 1) {
			if ((from & 1) != 0) { max_ = max(max_, segtree[from++]); }
			if ((to & 1) != 0) { max_ = max(max_, segtree[--to]); }
		}
		return max_;
	}
};