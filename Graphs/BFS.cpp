/*
    ============================================
    BFS ON GRAPH
    Time: O(n * m)
    ============================================
*/

void BFS(int n, vector<vector<int> > &adj) {
    queue<int> q;
    vector<int> vis(n + 1, -1);
    q.emplace(1);
    vis[1] = 1;
    vector<int> path(n + 1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &v: adj[u]) {
            if (vis[v] != -1) continue;
            vis[v] = vis[u] + 1;
            q.emplace(v);
            path[v] = u;
        }
    }
}


/*
    ============================================
    BFS ON GRID
    Time: O(n * m)
    ============================================
*/

void BFS(int n, vector<vector<int> > &adj) {
    queue<pii> q;
    vector<vector<int> > vis(n, vector<int>(m, -1));

    q.emplace(startX, startY);
    vis[startX][startY] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dirX[i], ny = y + dirY[i];

            if (nx < 0 || nx >= n or ny < 0 or ny >= m or
                v[nx][ny] == '#' || vis[nx][ny] != -1)
                continue;

            vis[nx][ny] = vis[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
}


