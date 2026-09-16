struct node {
    long long v;
    node (long long v_): v(v_) {}
    node (): v(0) {}
};

vector <long long> arr;
vector <node> segtree;
vector <long long> lazy;

node merge (node l, node r) {
    return node(l.v + r.v);
}

void push (int p, int l, int r) {
    
    if (lazy[p]) {
        segtree[p].v += (r - l + 1) * lazy[p];

        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }

        lazy[p] = 0;
    }
}

void build (int p, int l, int r) {
    if (l == r) {
        segtree[p] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    segtree[p] = merge(segtree[2*p], segtree[2*p+1]);
}

void update (int p, int l, int r, int lq, int rq, long long v) {
    push(p, l, r);

    if (l > rq || r < lq) return;
    if (lq <= l && rq >= r) {
        lazy[p] += v;
        push(p, l, r);
        return;
    }

    int mid = (l + r)/2;
    update(2*p, l, mid, lq, rq, v);
    update(2*p+1, mid+1, r, lq, rq, v);
    segtree[p] = merge(segtree[2*p], segtree[2*p+1]);
}

node query (int p, int l, int r, int lq, int rq) {
    push(p, l, r);

    if (l > rq || r < lq) return node();
    if (lq <= l && rq >= r) return segtree[p];
    
    int mid = (l + r) / 2;
    return merge(query(2*p, l, mid, lq, rq), query(2*p+1, mid+1, r, lq, rq));
}
