/*
    ============================================
    PRIM'S ALGORITHM - MST
    Time: O((V + E) log E)
    ============================================
*/

auto prim = [&]() -> int {
    vector<int> vis(n + 1);
    priority_queue<array<int, 3>, vector<array<int, 3> >, greater<> > pq;
    pq.push({0, 1, 0});
    int node = 0, sum = 0;
    while (pq.size()) {
        auto [cost, u, p] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = 1, node++;

        if (p) {
            mst[u].emplace_back(p, cost);
            mst[p].emplace_back(u, cost);
            sum += cost;
        }

        if (node == n) break;

        for (auto [v, w]: adj[u]) {
            if (vis[v]) continue;
            pq.push({w, v, u});
        }
    }
    return sum;
};


/*
    ============================================
    KRUSKAL'S ALGORITHM - MST
    Time: O(E log E + E log V)
    ============================================
*/

struct DSU {
    int n, comp;
    vector<int> leader;
    vector<int> val;

    void init(int sz) {
        n = sz;
        comp = sz;
        leader.resize(n + 1);
        val.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            leader[i] = i;
            val[i] = 1;
        }
    }

    int parent(int u) {
        if (u == leader[u])
            return u;
        return parent(leader[u]);
    }

    bool merge(int u, int v) {
        u = parent(u), v = parent(v);

        if (u == v)
            return false;

        if (val[u] < val[v])
            swap(u, v);
        leader[v] = u;
        val[u] += val[v];
        comp--;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu;
    dsu.init(n);
    vector<array<ll, 3> > v(m);
    for (int i = 0; i < m; ++i) {
        auto &[a, b, c] = v[i];
        cin >> c >> b >> a;
    }
    sort(all(v));
    ll ans = 0;
    for (auto &[c, a, b]: v) {
        if (dsu.merge(a, b))
            ans += c;
        if (dsu.comp == 1) break;
    }
    cout << ans << el;
}
