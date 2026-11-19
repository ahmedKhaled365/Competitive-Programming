/*
    ============================================
    LCA
    Build: O(N log N)
    Kth Ancestor: O(log N)
    LCA: O(log N)
    ============================================
*/

int n, q, anc[N][Log], lvl[N];
vector<vector<int> > adj;

void build(int u, int p) {
    anc[u][0] = p;
    if (p != -1)
        lvl[u] = lvl[p] + 1;
    for (int i = 1; i < 21; ++i) {
        int parent = anc[u][i - 1];
        if (parent == -1) {
            anc[u][i] = -1;
            continue;
        }
        anc[u][i] = anc[parent][i - 1];
    }

    for (int i = 0; i < adj[u].size(); ++i) {
        if (adj[u][i] == p) continue;
        build(adj[u][i], u);
    }
}

int kth_ancestor(int u, int k) {
    for (int i = 20; i >= 0; --i) {
        if (k >> i & 1) {
            u = anc[u][i];
            if (u == -1) return u;
        }
    }
    return u;
}

int lca(int u, int v) {
    if (lvl[u] < lvl[v])
        swap(u, v);
    u = kth_ancestor(u, lvl[u] - lvl[v]);
    if (u == v) return u;
    for (int i = Log - 1; i >= 0; --i) {
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}


/*
    ============================================
    LCA (if you have parents)
    Build: O(N log N)
    Kth Ancestor: O(log N)
    LCA: O(log N)
    ============================================
*/

int n, q, anc[N][Log];
vector<int> parent;

void build() {
    for (int i = 1; i <= n; ++i) {
        anc[i][0] = parent[i];
    }

    for (int i = 1; i < 31; ++i) {
        for (int j = 1; j <= n; ++j) {
            int p = anc[j][i - 1];
            anc[j][i] = anc[p][i - 1];
        }
    }
}

int kth_ancestor(int u, int k) {
    for (int i = 30; i >= 0; --i) {
        if (k >> i & 1) {
            u = anc[u][i];
            if (u == -1) return u;
        }
    }
    return u;
}


/*
    ============================================
    LCA WITH SPARSE TABLE (BINARY LIFTING)
    Build: O(N log N)
    Kth Ancestor: O(log N)
    LCA: O(log N)
    ============================================
*/

int n, m, anc[N][Log], lvl[N], mx[N][Log];
vector<vector<pair<int, int> > > adj, mst;

void build(int u, int p, int cost) {
    if (p == 0)
        lvl[u] = 0;
    else
        lvl[u] = lvl[p] + 1;
    anc[u][0] = p;
    mx[u][0] = cost;
    for (int i = 1; i < Log; ++i) {
        int parent = anc[u][i - 1];
        anc[u][i] = anc[parent][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[parent][i - 1]);
    }

    for (auto [v, w]: mst[u]) {
        if (v == p) continue;
        build(v, u, w);
    }
}

pair<int, int> kth_anc(int u, int k) {
    int maximum = 0;
    for (int i = Log - 1; i >= 0; --i) {
        if (k >> i & 1) {
            maximum = max(maximum, mx[u][i]);
            u = anc[u][i];
        }
    }
    return {u, maximum};
}

int lca(int u, int v) {
    if (lvl[u] < lvl[v])
        swap(u, v);
    u = kth_anc(u, lvl[u] - lvl[v]).first;
    if (u == v) return u;
    for (int i = Log - 1; i >= 0; --i) {
        if (anc[u][i] != anc[v][i])
            u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
}
