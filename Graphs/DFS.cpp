/*
    ============================================
    DFS ON GRAPH
    Time: O(V + E)
    ============================================
*/

int n, m;
vector<vector<int>> adj;
vector<int> vis;

void dfs(int u, int p) {
    vis[u] = 1;

    for (auto v : adj[u]) {
        if (v == p or vis[v]) continue;
        dfs(v, u);
    }
}


/*
    ============================================
    DFS ON GRID
    Time: O(n * m)
    ============================================
*/

int n, m, sol = 0;
vector<string> v;

void dfs(int i, int j) {
    if (i < 0 || i >= n or j < 0 or j >= m or v[i][j] == '#')
        return;
    v[i][j] = '#';
    for (int k = 0; k < 4; ++k) {
        dfs(i + dirX[k], j + dirY[k]);
    }
}
