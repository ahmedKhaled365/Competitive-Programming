
const int N = 1e7 + 1;

// ============================================
// 1. PRIME CHECK
// Time: O(sqrt(n))
// ============================================

bool is_prime(ll n) {
    if (n == 2) return true;
    if (n < 2 or n % 2 == 0) return false;

    for (ll i = 3; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }

    return true;
}


// ============================================
// 2. FAST POWER
// Time: O(log n)
// ============================================

int fast_pow(int a, int n) {
    if (!n) return 1;

    int p = fast_pow(a, n >> 1);
    p = mul(p, p);

    if (n & 1)
        p = mul(p, a);

    return p;
}

// ============================================
// 3. PRIME FACTORIZATION
// Time: O(sqrt(n))
// ============================================

vector<int> factorize(int n) {
    vector<int> ans;

    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            ans.emplace_back(i);
        }
    }

    if (n > 1) {
        ans.emplace_back(n);
    }

    return ans;
}


// ============================================
// 4. GET DIVISORS
// Time: O(sqrt(n))
// ============================================

vector<int> getDivisors(int n) {
    vector<int> divs;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);

            if (i != (n / i))
                divs.push_back(n / i);
        }
    }

    return divs;
}


// ============================================
// 5. SIEVE OF ERATOSTHENES
// Time: O(N log log N)
// ============================================

bool isPrime[N];

void sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}


// ============================================
// 6. SMALLEST PRIME FACTOR (SPF)
// Time: O(N log log N)
// ============================================

int spf[N];

void SPF() {
    for (int i = 1; i < N; ++i) {
        spf[i] = i;
    }

    for (int i = 2; i < N; ++i) {
        if (spf[i] != i) continue;

        for (int j = 2 * i; j < N; j += i) {
            if (spf[j] == j)
                spf[j] = i;
        }
    }
}


// ============================================
// 7. PRIME FACTORIZATION USING SPF
// in SPF you get the Prime factors in increasing order. ex: 2 2 2 3 5 5 7 7.. etc.
// Time: O(log n) after preprocessing
// ============================================

vector<int> query(int i) {
    vector<int> ans;
    int num = i;

    while (num > 1) {
        int x = spf[num];

        while (num % x == 0) {
            num /= x;
            // make ans.push_back(x) here if you need each freq
        }

        ans.push_back(x);
    }

    return ans;
}
