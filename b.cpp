#include <bits/stdc++.h>
using namespace std;

// Little Sunday <3

vector <long long> seg;
vector <long long> mIdx;

void build (int p, int l, int r) {
    if (l == r) {
        seg[p] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    build (2*p, l, mid);
    build (2*p+1, mid+1, r);
    seg[p] = max(seg[2*p], seg[2*p+1]);
}

void update (int p, int l, int r, int idx, long long v) {

    if (

}

long long query (int l, int r, int lq, int rq) {
    if (l > rq || r < lq) return LLONG_MIN; 
    if (lq <=l && rq <= r) return seg[p];

    int mid = (l + r) / 2;
    return max(query(l, mid, lq, rq), query(mid+1, r, lq, rq));
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    seg.resize(4*n);
    mIdx.resize(n);

    vector <long long> arr (n);

    for (int i = 0; i<n; i++) cin >> arr[i];
    
    map <long long, int> m;
    vector <long long> mIdx (n);
    for (int i = 0; i<n; i++) {
        if (m.find(arr[i]) != m.end()) {
            mIdx[i] = m[arr[i]];
            m[arr[i]] = i;
        }
        else {
            mIdx[i] = -1;
            m[arr[i]] = i;
        }
    }

    while (q--) {
        int type; cin >> type;

        if (type == 1) {
            int idx; long long v;
            cin >> idx >> v;
            update(1, 0, n-1, idx-1, v);
        }

        else {
            int l, r;
            cin >> l >> r;

            long long idx = query(1, 0, n-1, l-1, r-1);
            if (idx < l) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
    }
}
