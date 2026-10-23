#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int n, m;
vector<pair<int, int>> adj[N];
int tin[N], low[N], is_bridge[N];
int timer;
int cnt;

void dfs(int v, int p_edge = -1) {
    tin[v] = low[v] = ++timer;
    
    for (auto& edge : adj[v]) {
        int to = edge.first;
        int edge_id = edge.second;
        
        if (edge_id == p_edge) continue;
        
        if (tin[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, edge_id);
            low[v] = min(low[v], low[to]);
            
            if (low[to] > tin[v]) {
                is_bridge[edge_id] = 1;
                cnt++;
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        tin[i] = low[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!tin[i]) dfs(i);
    }
}

vector <bool> vis (N, false);
vector <bool> used (N, false);
vector <pair<int, int>> roots;

void dfs2 (int v) {
    vis[v] = true;

    for (auto [u, i]: adj[v]) {
        if (used[i]) continue;

        used[i] = true;
        roots.push_back({v, u});

        if (!vis[u]) {
            dfs2(u);
        }
    }
}

 
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;

    for (int i = 0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    find_bridges();

    if (cnt > 0) {
        cout << 0 << "\n";
        return 0;
    }

    dfs2(0);
    for (auto [v, u]: roots) {
        cout << v+1 << " " << u+1 << "\n";
    }

    return 0;

}

// Little Sunday <3
