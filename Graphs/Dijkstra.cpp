/*
    ============================================
    Dijkstra
    Time: O((V + E) Log V)
    ============================================
*/

void Dijkstra(int start, int goal, vector<vector<pair<int, int> > > &v) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    // starting at node 1 with cost 0.
    pq.emplace(0, 1);
    vector<int> vis(n + 1, -1);

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (vis[node] != -1) continue;
        vis[node] = cost;

        for (auto [u, edge]: v[node]) {
            pq.emplace(cost + edge, u);
        }
    }
}
