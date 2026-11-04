vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> gin(n + 1);

    for (int u = 1; u <= n; u++)
        for (int v : adj[u])
            gin[v]++;

    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (gin[i] == 0)
            q.push(i);

    vector<int> vec;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        vec.push_back(u);

        for (int v : adj[u]) {
            gin[v]--;

            if (gin[v] == 0)
                q.push(v);
        }
    }

    if (vec.size() != n)
        return {};

    return vec;
}
