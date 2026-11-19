
struct lazySegTree {
    int sz;
    vector<int> seg, lazy;
 
#define lf (2 * x + 1)
#define rt (2 * x + 2)
#define mid ((lx + rx) >> 1)
 
    void init(int n) {
        sz = 4 * n;
        seg.assign(sz, 0);
        lazy.assign(sz, {});
    }
 
    int merge(int a, int b) {
        return min(a, b);
    }
 
    void propagate(int x, int lx, int rx) {
        /// do your work here to accumulate the updates to the lower level nodes.
        if (lx != rx) {
            lazy[lf] += lazy[x];
            lazy[rt] += lazy[x];
        }
        seg[x] += lazy[x];
        lazy[x] = 0;
    }
 
    void update(int l, int r, int val, int x, int lx, int rx) {
        propagate(x, lx, rx);
 
        if (rx < l or r < lx) return;
        if (l <= lx and rx <= r) {
            lazy[x] += val;
            propagate(x, lx, rx);
            return;
        }
 
        update(l, r, val, lf, lx, mid);
        update(l, r, val, rt, mid + 1, rx);
 
        seg[x] = merge(seg[lf], seg[rt]);
    }
 
    int query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
 
        if (rx < l or r < lx)
            return LONG_LONG_MAX;
        if (l <= lx and rx <= r)
            return seg[x];
 
        return merge(query(l, r, lf, lx, mid), query(l, r, rt, mid + 1, rx));
    }
};