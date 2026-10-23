const int N = 3e5 + 10;
int n, m;
vector<pair<int, int>> adj[N];
int tin[N], low[N], is_bridge[N];
int timer;

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
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    for (int i = 0; i < n; i++) {
        tin[i] = low[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!tin[i]) dfs(i);
    }
}
