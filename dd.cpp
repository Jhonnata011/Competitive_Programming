#include <bits/stdc++.h>

using namespace std;
// Little Sunday <3

vector <long long> bit;

void add (int p, int n, long long v) {
    for (; p<=n; p+=(p&-p)) bit[p] += v;
}

long long query (int p) {
    long long ans = 0;
    for (; p>0; p-=(p&-p)) ans += bit[p];
    return ans;
}

long long query (int l, int r) {
    return (query(r) - query(l-1));
}

vector <vector <int>> adj;
vector <long long> arr;
vector <int> tin;
vector <int> tout;
vector <int> parent;
int t = 1;

void dfs (int v, int p) {
    
    tin[v] = t++;

    for (int u: adj[v]) {
        if (u == p) continue;
        parent[u] = v;
        dfs(u, v);
    }

    tout[v] = t-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    adj.resize(n+1);
    arr.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);
    parent.resize(n+1);
    bit.resize(n+1);

    for (int i = 1; i<=n; i++) cin >> arr[i];

    for (int i = 0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    for (int i = 1; i<=n; i++) {
        add(tin[i], n, arr[i]);
    }

    while (q--) {
        
        int type; cin >> type;

        if (type == 1) {
            int idx; cin >> idx;
            long long x; cin >> x;
            add(tin[idx], n, x - arr[idx]);
            arr[idx] = x;
        }
        
        else {
            int idx; cin >> idx;
            long long ans = query(1, tin[idx]);
            if (parent[idx] != 0) {
                ans -= query(tin[parent[idx]], tin[idx]);
            }
            cout << ans << "\n";
        }
    }
    

    return 0;
}
