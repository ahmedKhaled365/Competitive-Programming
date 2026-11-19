
/*
    ============================================
    DSU - DISJOINT SET UNION
    ============================================

    Init: O(n)
    Parent: O(log n)
    Merge: O(log n)
*/

struct DSU {
    int n;
    vector<ll> leader, cnt;

    void init(int sz) {
        n = sz;
        leader.resize(n + 1);
        cnt.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            leader[i] = i;
        }
    }

    int parent(int u) {
        if (u == leader[u]) return u;
        return parent(leader[u]);
    }

    bool merge(int u, int v) {
        u = parent(u), v = parent(v);

        if (u == v)
            return false;

        if (cnt[u] < cnt[v])
            swap(u, v);

        leader[v] = u;
        cnt[u] += cnt[v];
        return true;
    }
};
