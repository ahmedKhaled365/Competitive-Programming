

vector<int> arr;

struct segTree {
    int sz;
    vector<int> seg;

#define lf (2 * x + 1)
#define rt (2 * x + 2)
#define mid ((lx + rx) / 2)

    void init(int n) {
        sz = 4 * n;
        seg.assign(sz, {});

        build(0, 0, n - 1);
    }

    int merge(int a, int b) {
        return a + b;
    }

    void build(int x, int lx, int rx) {
        if (lx == rx) {
            /// leaf node
            seg[x] = arr[lx];
            return;
        }

        build(lf, lx, mid);
        build(rt, mid + 1, rx);

        seg[x] = merge(seg[lf], seg[rt]);
    }

    void update(int i, int val, int x, int lx, int rx) {
        if (lx == rx) {
            seg[x] = val;
            arr[i] = val;
            return;
        }

        if (i <= mid) {
            update(i, val, lf, lx, mid);
        } else {
            update(i, val, rt, mid + 1, rx);
        }

        seg[x] = merge(seg[lf], seg[rt]);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (rx < l or r < lx)
            return 0;

        if (l <= lx and rx <= r)
            return seg[x];

        return merge(query(l, r, lf, lx, mid), query(l, r, rt, mid + 1, rx));
    }

#undef mid
};
