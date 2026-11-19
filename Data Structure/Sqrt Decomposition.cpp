int n, q, arr[N], block[SQ];

void update(int idx, int val) {
    int blockNum = idx / SQ;
    block[blockNum] += val - arr[idx];
    arr[idx] = val;
}

int query(int l, int r) {
    int ret = 0;
    while (l <= r) {
        if (l % SQ == 0 and r - l >= SQ) {
            ret += block[l / SQ];
            l += SQ;
            continue;
        }
        ret += arr[l++];
    }
    return ret;
}

void solve() {
    cin >> n >> q;
    memset(block, 0, sizeof block);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        block[i / SQ] += arr[i];
    }

    int t, k, u, a, b;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> k >> u;
            update(--k, u);
        } else {
            cin >> a >> b;
            cout << query(--a, --b) << el;
        }
    }
}
