
/*
    ============================================
    MO'S ALGORITHM
    Time: O((n + Q) * sqrt(n))
    ============================================
*/

void solve() {
    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<array<int, 3>> queries(t);
    for (int i = 0, l, r; i < t; ++i) {
        cin >> l >> r;
        queries[i] = {--l, --r, i};
    }

    sort(all(queries), [&](array<int, 3> a, array<int, 3> b) {
        return make_pair(a[0] / SQ, a[1]) < make_pair(b[0] / SQ, b[1]);
    });

    ll cnt = 0;

    auto add = [&](int idx) {
        // Update current answer after adding arr[idx].
    };

    auto remove = [&](int idx) {
        // Update current answer after removing arr[idx].
    };

    vector<ll> ans(t);
    int l = 0, r = -1;

    for (const auto [lq, rq, iq]: queries) {
        while (lq < l) add(--l);
        while (r < rq) add(++r);

        while (l < lq) remove(l++);
        while (rq < r) remove(r--);

        ans[iq] = cnt;
    }

    for (auto a: ans)
        cout << a << el;
}
