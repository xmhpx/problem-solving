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


struct node{
    node* cl{};
    node* cr{};
    long long la{0};
	long long mx{0};
    int l, r;

    node(int _l, int _r) : l(_l), r(_r) {}

	inline void merge(){
		mx = max(cl->mx, cr->mx);
	}

	inline void push(){
		cl->la += la;
		cr->la += la;
		cl->mx += la;
		cr->mx += la;
		la = 0;
	}

    long long ask(int po){
        if(l == r){
            return mx;
        }

        int m = (l+r)/2;
        if(!cl){
            cl = new node(l, m);
        }
        if(!cr){
            cr = new node(m+1, r);
        }
		push();
        if(po <= m){
            return cl->ask(po);
        }
        else{
            return cr->ask(po);
        }
    }

    void add(int ql, int qr, int vl){
        if(qr < ql)return;
        if(qr < l || r < ql)return;
        if(ql <= l && r <= qr){
            la += vl;
            return;
        }

        int m = (l+r)/2;
        if(!cl){
            cl = new node(l, m);
        }
        if(!cr){
            cr = new node(m+1, r);
        }
		push();
        cl->add(ql, qr, vl);
        cr->add(ql, qr, vl);
		merge();
    }
};