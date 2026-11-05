#include <bits/stdc++.h>
 
using namespace std;
 
// Little Sunday <3

vector <set <int>> colors;
vector <vector <int>> adj;
vector <long long> ans;

void dfs (int v, int p) {
    
    vector <int> a;
    
    for (int u: adj[v]) {
        if (u == v) continue;
        dfs(u, v);
        a.push_back(u);
        if (colors[v].size() < colors[u].size()) swap(colors[v], colors[u]);
    }

    for (int u: a) {
        for (int x: colors[u]) colors[v].insert(x);
    }

    ans[v] = colors[v].size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;

    colors.resize(n+1);
    adj.resize(n+1);
    ans.resize(n+1);

    for (int i = 1; i<=n; i++) {
        int x; cin >> x;
        colors[i].insert(x);
    }
    
    for (int i = 0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    for (int i = 1; i<=n; i++) cout << ans[i] << " ";
    cout << "\n";




}
