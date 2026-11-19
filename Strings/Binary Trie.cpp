struct Node {
    int ch[2]{};
    int freq = 0, end = 0;

    int &operator[](char x) {
        return ch[x];
    }
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

    void insert(int x, int op) {
        int u = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = x >> i & 1;
            if (!trie[u][bit])
                trie[u][bit] = newNode();
            u = trie[u][bit];
            trie[u].freq += op;
        }
        trie[u].end += op;
    }

    int XorMin(int x) {
        int u = 0, ret = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = x >> i & 1;
            if (trie[trie[u][bit]].freq > 0) {
                u = trie[u][bit];
            } else {
                ret |= (1LL << i);
                u = trie[u][!bit];
            }
        }
        return ret;
    }
};
