vector<vector<int>> adj;
vector<int> tin, tout;
vector <int> et;
int timer = 0;

void dfs_single(int v, int p) {
    et[timer] = v;
    tin[v] = timer++;

    for (int u : adj[v]) {
        if (u != p) {
            dfs_single(u, v);
        }
    }
    tout[v] = timer - 1;
}

void dfs_double_post(int v, int p) {
    et[timer] = v;
    tin[v] = timer++;

    for (int u : adj[v]) {
        if (u != p) {
            dfs_double_post(u, v);
        }
    }

    tout[v] = timer;
    et[timer++] = v;
}
