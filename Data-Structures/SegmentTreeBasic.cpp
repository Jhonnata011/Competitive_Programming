#include <bits/stdc++.h>

using namespace std;


struct node
{
    long long v;

    node (long long v_): v(v_) {}
    node (): v(0L) {}
};

vector <node> segtree;
vector <long long> arr;

node merge (node left, node right) {
    return node(left.v + right.v);
}

void build (int p, int l, int r) {
    
    if (l == r) {
        segtree[p] = node(arr[l]);
        return;
    }

    int mid = (l + r) / 2;

    build(2*p, l, mid);
    build(2*p+1, mid+1, r);

    segtree[p] = merge(segtree[2*p], segtree[2*p+1]);
}

void uptade (int p, int l, int r, int idx, long long v) {

    if (l == r) {
        segtree[p] = node(v);
        return;
    }

    int mid = (l + r) / 2;
    if (idx <= mid) uptade (2*p, l, mid, idx, v);
    else uptade(2*p+1, mid+1, r, idx, v);

    segtree[p] = merge(segtree[2*p], segtree[2*p+1]);
}

node query (int p, int l, int r, int lq, int rq) {

    if (l > rq || r < lq) return node();
    if (lq <= l && rq >= r) return segtree[p];
    int mid = (l + r) / 2;
    return merge(query(2*p, l, mid, lq, rq), query(2*p+1, mid+1, r, lq, rq));

}