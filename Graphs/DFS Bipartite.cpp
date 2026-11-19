
/*
    ============================================
    CHECK BIPARTITE GRAPH USING DFS
    Time: O(V + E)
    ============================================
*/

int n, m;
vector<vector<int>> v;
vector<int> vis;

void dfs(int u, int p) {
    if (p == -1)
        vis[u] = 1;
    else
        vis[u] = 3 - vis[p]; /// team with vis = 1, and other team with vis = 2

    for (int i = 0; i < v[u].size(); ++i) {
        if (v[u][i] == p) continue;

        if (vis[v[u][i]] == vis[u]) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        if (!vis[v[u][i]])
            dfs(v[u][i], u);
    }
}
