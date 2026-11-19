/*
    ============================================
          NCR MOD P - FERMAT'S LITTLE THEOREM
    ============================================

    Preprocessing: O(N + log M)
    nCr Query: O(1)
*/

const int N = 2e5 + 1;
const ll M = 998244353;

ll fact[N];
ll inv[N];

ll mul(ll a, ll b) {
    return (a % M * b % M) % M;
}

ll add(ll a, ll b) {
    return (a % M + b % M + M) % M;
}

ll fast_pow(ll a, ll b) {
    if (!b) return 1LL;

    ll p = fast_pow(a, b >> 1LL);
    p = mul(p, p);

    if (b & 1LL) {
        p = mul(p, a);
    }

    return p;
}

ll modInverse(ll n) {
    return fast_pow(n, M - 2);
}

void preProcess() {
    fact[0] = 1;

    for (int i = 1; i < N; ++i) {
        fact[i] = mul(i, fact[i - 1]);
    }

    inv[N - 1] = modInverse(fact[N - 1]);

    for (int i = N - 2; i >= 0; --i) {
        inv[i] = mul(inv[i + 1], (i + 1));
    }
}

ll nCrModPFermat(ll n, ll r) {
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;

    // Base case
    if (r == 0)
        return 1;

    return mul(fact[n], mul(inv[n - r], inv[r]));
}
