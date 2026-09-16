#include <bits/stdc++.h>
using namespace std;

// Little Sunday <3

const int MAXN = 100000;

struct Node {
    int v;
    int left;
    int rigth;
};

vector <int> arr;

Node nodes[MAXN * 20];
int roots[MAXN];

int idxRoot = 0;
int cntNodes = 0;

int add (int rootPrev, int l, int r, int v) {
    int current = ++cntNodes;
    nodes[current] = nodes[rootPrev];

    nodes[current].v ++;

    if (l == r) {
        return current;
    }

    int mid = (l + r) / 2;

    if (v <= mid) {
        nodes[current].left = add(nodes[rootPrev].left, l, mid, v);
    
    }
    else {
        nodes[current].rigth = add(nodes[rootPrev].rigth, mid+1, r, v);
    }

    return current;

}

int query (int l, int r, int lq, int rq, int k) {

    if (l == r) return l;

    int countL = nodes[nodes[rq].left].v - nodes[nodes[lq].left].v;

    int mid = (lq + rq) / 2;

    if (countL >= k) return query(l, r, lq, mid, k);
    else return query(l, r, mid+1, r, k-countL);


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin  >> n >> q;

    arr.resize(n);
    for (int i = 0; i<n; i++) cin >> arr[i];

    vector <int> comp = arr;

    sort (comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    vector <int> result (n);
    for (int i = 0; i<n; i++) {
        result[i] = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin();
    }

    for (int i = 0; i<n; i++) {
        add(i, 0, i, result[i]);
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        
        int ans = query(0, n-1, l-1, r-1, k);
        cout << ans << "\n";

    }   
}
