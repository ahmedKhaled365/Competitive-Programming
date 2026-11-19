/// Polynomial hash

string s;
const int base1 = 31, base2 = 37, mod1 = 1e9 + 7, mod2 = 2e9 + 11;
int n, pw1[N], pw2[N];
vector<pair<int, int> > pre, suf;

void push(vector<pair<int, int> > &v) {
    int h1 = 0, h2 = 0;
    for (int i = 0; i < n; ++i) {
        v[i] = {h1, h2};
        int c = s[i] - 'a' + 1;
        h1 = (h1 * base1) % mod1;
        h1 = (h1 + c) % mod1;

        h2 = (h2 * base2) % mod2;
        h2 = (h2 + c) % mod2;
    }
    v[n] = {h1, h2};
}

pair<int, int> clc(int l, int r, vector<pair<int, int> > &v) {
    auto ret = v[r];
    int sz = r - l + 1;
    l--;
    ret.first = (ret.first - (v[l].first * pw1[sz]) % mod1 + mod1) % mod1;
    ret.second = (ret.second - (v[l].second * pw2[sz]) % mod2 + mod2) % mod2;
    return ret;
}

bool palindrome(int l, int r) {
    return clc(l, r, pre) == clc(n - r + 1, n - l + 1, suf);
}


/// for finding the longest palindrome.
bool valid(int length) {
    for (int l = 1, r = length; r <= n; ++l, r++) {
        if (palindrome(l, r))
            return true;
    }
    return false;
}

ll bsOdd() {
    ll st = 0, e = n / 2;
    while (st < e) {
        ll mid = st + (e - st + 1) / 2;
        if (valid(2 * mid + 1)) st = mid;
        else e = mid - 1;
    }
    return st * 2 + 1;
}

ll bsEven() {
    ll st = 0, e = n / 2;
    while (st < e) {
        ll mid = st + (e - st + 1) / 2;
        if (valid(2 * mid)) st = mid;
        else e = mid - 1;
    }
    return st * 2;
}
