struct node {
    long long v;

    node (long long v_): v(v_) {}
    node (): v(0LL) {}
};

node merge (node left, node right) {
    return node(left.v + right.v);
}

struct SegTree {
    int n;
    vector <node> tree;

    SegTree (const vector <long long>& arr): n(arr.size()), tree(4 * arr.size()) {
        if (n > 0) build(1, 0, n - 1, arr);
    }

    void update (int idx, long long v) {
        update(1, 0, n - 1, idx, v);
    }

    node query (int lq, int rq) {
        return query(1, 0, n - 1, lq, rq);
    }

private:
    void build (int p, int l, int r, const vector <long long>& arr) {
        if (l == r) {
            tree[p] = node(arr[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(2*p, l, mid, arr);
        build(2*p+1, mid+1, r, arr);

        tree[p] = merge(tree[2*p], tree[2*p+1]);
    }

    void update (int p, int l, int r, int idx, long long v) {
        if (l == r) {
            tree[p] = node(v);
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid) update(2*p, l, mid, idx, v);
        else update(2*p+1, mid+1, r, idx, v);

        tree[p] = merge(tree[2*p], tree[2*p+1]);
    }

    node query (int p, int l, int r, int lq, int rq) {
        if (l > rq || r < lq) return node();
        if (lq <= l && rq >= r) return tree[p];

        int mid = (l + r) / 2;
        return merge(query(2*p, l, mid, lq, rq), query(2*p+1, mid+1, r, lq, rq));
    }
};
