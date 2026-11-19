// ============================================
// 1. CUSTOM COMPARE FOR PRIORITY QUEUE
// ============================================

// 1.1 Bigger First, Smaller Second
// First: Descending
// Second: Ascending

struct cmp1 {
    bool operator()(const pair<int, int> &p1,
                    const pair<int, int> &p2) const {
        if (p1.first == p2.first)
            return p1.second > p2.second;

        return p1.first < p2.first;
    }
};


// 1.2 Bigger First, Bigger Second
// First: Descending
// Second: Descending

struct cmp2 {
    bool operator()(const pair<int, int> &p1,
                    const pair<int, int> &p2) const {
        if (p1.first == p2.first)
            return p1.second < p2.second;

        return p1.first < p2.first;
    }
};


// 1.3 Smaller First, Bigger Second
// First: Ascending
// Second: Descending

struct cmp3 {
    bool operator()(const pair<int, int> &p1,
                    const pair<int, int> &p2) const {
        if (p1.first == p2.first)
            return p1.second < p2.second;

        return p1.first > p2.first;
    }
};


// 1.4 Smaller First, Smaller Second
// First: Ascending
// Second: Ascending

struct cmp4 {
    bool operator()(const pair<int, int> &p1,
                    const pair<int, int> &p2) const {
        if (p1.first == p2.first)
            return p1.second > p2.second;

        return p1.first > p2.first;
    }
};

/*
    Usage for example:
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>, cmp1> pq;
*/


// ============================================
// 2. BINARY SEARCH - 11110000
// ============================================

int bs10(int s, int e) {
    while (s < e) {
        int mid = s + (e - s + 1) / 2;

        if (valid(mid))
            s = mid;
        else
            e = mid - 1;
    }

    return s;
}

// ============================================
// 3. BINARY SEARCH - 00001111
// ============================================

int binarySearchFirstTrue(int s, int e) {
    while (s < e) {
        int mid = s + (e - s) / 2;

        if (valid(mid))
            e = mid;
        else
            s = mid + 1;
    }

    return s;
}

