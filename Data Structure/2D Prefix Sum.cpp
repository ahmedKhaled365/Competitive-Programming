
/*
    ============================================
    2D PREFIX SUM

    PrefixSums<ll> pref;
    pref.init(v);

    // Query sum of rectangle (x1, y1) to (x2, y2)
    // 0-based, inclusive

    ll ans = pref.query(x1, x2, y1, y2);

    Build: O(R * C)
    Query: O(1)
    Space: O(R * C)

    ============================================
*/


template <class T>
struct PrefixSums {
    vector<vector<T>> sum;

    void init(const vector<vector<T>>& v) {
        int R = v.size(), C = v[0].size();
        sum.assign(R + 1, vector<T>(C + 1));

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                sum[i + 1][j + 1] = v[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
    }

    T query(int X1, int X2, int Y1, int Y2) { // 0-based
        X2++, Y2++;
        return sum[X2][Y2] - sum[X1][Y2] - sum[X2][Y1] + sum[X1][Y1];
    }
};
