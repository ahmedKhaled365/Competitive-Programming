struct Node {
    unordered_map<char, int> ch;
    int freq = 0, end = 0, mxEnd = 0;
    char mxEndDir{};

    int &operator[](char x) {
        return ch[x];
    }
};

struct item {
    string ret{};
    int cnt{};
};

struct Trie {
    vector<Node> trie;

    Trie() {
        newNode();
    }

    int newNode() {
        trie.emplace_back();
        return trie.size() - 1;
    }

    void insert(string &s, int op) {
        int u = 0, mx = 1;
        for (char x: s) {
            if (!trie[u][x]) {
                trie[u][x] = newNode();
            }
            u = trie[u][x];
            trie[u].freq += op;
        }
        trie[u].end += op;
        mx = max(mx, trie[u].end);
        u = 0;
        for (char x: s) {
            if (trie[u].mxEnd < mx) {
                trie[u].mxEnd = mx;
                trie[u].mxEndDir = x;
            } else if (trie[u].mxEnd == mx) {
                trie[u].mxEndDir = min(trie[u].mxEndDir, x);
            }
            u = trie[u][x];
        }
        trie[u].mxEnd = max(trie[u].mxEnd, mx);
    }

    item query(string &s) {
        int u = 0;
        string ret{};
        for (char x: s) {
            if (!trie[u][x])
                return {"-1", 0};
            u = trie[u][x];
            ret += x;
        }
        while (trie[u].end != trie[u].mxEnd) {
            ret += trie[u].mxEndDir;
            u = trie[u][trie[u].mxEndDir];
        }
        return {ret, trie[u].end};
    }
};
