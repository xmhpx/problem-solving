// Dinic's Algorithm
// copy the FlowGraph class and INF.
// use the constructor to initiate the graph with n vertices.
// use build to empty the graph and rebuild with the same n.
// use addEdge to add edges and maxFlow to calculate flow.
// restart the graph after each use.
// based on cp-algorithms

#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000005;

class FlowGraph{
public:
    struct edge {
        int v;
        int cap, flow;
        int rid;
    };

    int n;

    FlowGraph(int _n){
        n = _n;
        build();
    }

    vector<vector<edge>> adj;
    vector<int> dist, ptr;

    void build(){
        adj.clear();
        dist.clear();
        ptr.clear();
        adj.resize(n);
        dist = vector<int>(n, 0);
        ptr = vector<int>(n, 0);
    }

    void addEdge(int u, int v, int cap) {
        int id = adj[u].size(), 
            rid = adj[v].size();
        adj[u].push_back({v, cap, 0, rid});
        adj[v].push_back({u, 0, 0, id});
    }

    bool bfs(int s, int t){
        for(int i = 0; i < n; i++)dist[i] = -1;
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while(q.size()){
            int nw = q.front();
            q.pop();
            for(auto e : adj[nw]){
                if(e.cap == e.flow)continue;
                if(dist[e.v] == -1){
                    dist[e.v] = dist[nw]+1;
                    q.push(e.v);
                }
            }
        }

        return dist[t] != -1;
    }

    int dfs(int nw, int t, int f){
        if(nw == t)return f;
        for(; ptr[nw] < adj[nw].size(); ptr[nw]++){
            auto &e = adj[nw][ptr[nw]];
            if(dist[e.v] == dist[nw]+1 && e.cap > e.flow){
                int rf = min(f, e.cap - e.flow);
                rf = dfs(e.v, t, rf);
                if(rf == 0)continue;
                e.flow += rf;
                adj[e.v][e.rid].flow -= rf;
                return rf;
            }
        }
        return 0;
    }

    int maxFlow(int s, int t){
        int r = 0;
        while(bfs(s, t)){
            ptr = vector<int>(n, 0);
            int f = 0;
            do{
                r += f;
                f = dfs(s, t, INF);
            }while(f > 0);
        }
        return r;
    }
};

signed main(){
    int n, m;
    cin >> n >> m;

    // initiate the graph
    FlowGraph grph(n);

    // add edges
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        grph.addEdge(u, v, c);
    }

    // s = start, t = end
    int s, t;
    cin >> s >> t;

    // max flow from s to t
    cout << grph.maxFlow(s, t) << '\n';
}