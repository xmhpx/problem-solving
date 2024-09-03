// TwoSat
// copy the TwoSatGraph class.
// use the constructor to initiate the graph with n vertices.
// use addEdge to add edges and solve2SAT to solve.
// based on cp-algorithms.

#include <bits/stdc++.h>

using namespace std;

class TwoSatGraph{
public:

    int n;

    TwoSatGraph(int _n){
        n = _n<<1;
        build();
    }

    vector<vector<int>> g, reg;

    void build(){
        g.clear();
        g.resize(n);
        reg.clear();
        reg.resize(n);
    }

    void innerAddEdge(int u, int v){
        g[u].push_back(v);
        reg[v].push_back(u);
    }

    void addEdge(int u, bool nu, int v, bool nv) {
        u = u<<1^nu;
        v = v<<1^nv;
        innerAddEdge(u, v);
        innerAddEdge(v^1, u^1);
    }

    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    void dfs1(int v) {
        used[v] = true;
        for (int u : g[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : reg[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }
    
    bool solve2SAT() {
        order.clear();
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int v = order[n - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n / 2, false);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }
};

signed main(){
    int n, m;
    cin >> n >> m;

    // initiate the graph
    TwoSatGraph grph(n);

    // add edges
    for(int i = 0; i < m; i++){
        int u, v;
        int nu, nv;
        cin >> u >> nu >> v >> nv;
        grph.addEdge(u, nu, v, nv);
    }

    cout << grph.solve2SAT();
}