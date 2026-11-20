// Isomorfismo de arvores - AHU exato (sem hash, sem colisao)

// Cada subarvore recebe um id: o vetor ORDENADO dos ids dos filhos e
// mapeado para um inteiro. Duas subarvores sao isomorfas se tem o mesmo id.

// rooted(r)  : id da arvore enraizada em r (id[v] = id da subarvore de v)
// unrooted() : id da arvore sem raiz (usa o(s) centroide(s))
// O(n log n), iterativo (sem risco de estourar a pilha).

map<vector<int>, int> ids;

int get_id(vector<int> &v) {
    sort(v.begin(), v.end());
    auto it = ids.find(v);
    if (it == ids.end()) it = ids.emplace(v, (int) ids.size()).first;
    return it->second;
}

struct tree {
    int n;
    vector<vector<int>> g;
    vector<int> id; // id[v] = id da subarvore de v (apos rooted)
    
    tree(int n) : n(n), g(n), id(n) {}
    
    void add_edge(int a, int b) { 
      g[a].push_back(b), g[b].push_back(a);
    }

    vector<int> bfs(int r, vector<int> &par, int ban = -1) {
        vector<int> ord{r};
        par[r] = ban;
        for (int i = 0; i < (int) ord.size(); i++)
            for (int u : g[ord[i]]) if (u != par[ord[i]])
                par[u] = ord[i], ord.push_back(u);
        return ord;
    }

    // ISOMORFISMO EM ARVORES ENRAIZADAS
    int rooted(int r, int ban = -1) {
        vector<int> par(n);
        vector<int> ord = bfs(r, par, ban);
        for (int i = (int) ord.size() - 1; i >= 0; i--) {
            int v = ord[i];
            vector<int> ch;
            for (int u : g[v]) if (u != par[v]) ch.push_back(id[u]);
            id[v] = get_id(ch);
        }
        return id[r];
    }

    vector<int> centroids() {
        vector<int> par(n), sz(n, 1), cs;
        vector<int> ord = bfs(0, par);
        for (int i = n - 1; i >= 0; i--) {
            int v = ord[i], mx = n - sz[v];
            for (int u : g[v]) if (u != par[v]) mx = max(mx, sz[u]);
            if (mx <= n / 2) cs.push_back(v);
            if (i) sz[par[v]] += sz[v];
        }
        return cs;
    }

    // ISOMORFISMO EM ARVORES NAO ENRAIZADAS
    int unrooted() {
        vector<int> cs = centroids();
        if (cs.size() == 1) return rooted(cs[0]);
        vector<int> v = {-1, rooted(cs[0], cs[1]), rooted(cs[1], cs[0])};
        return get_id(v);
    }
};
