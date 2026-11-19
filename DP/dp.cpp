/*
 *** NOTES ***
- 0/1 knapsack (subset dp)
- a[i]: pick/leave -> (i + 1)

- knapsack ->
dp[....][ j ] = ans
         1e9  = 1e3
dp[....][ans] = j -> (greedy)

- Ranges 1: (general ranges): [DONE]
    dp[l][r] = ans

- Ranges 2:
[x x x] [x x] [x] [x x x]

dp[l] = min:
          for r = l; r < n; ++r :
            cost(l, r) + dp[r + 1]

dp[l][r] = min(
    cost(l, r) + dp[r + 1][r + 1],
    dp[l][r + 1]
)

dp[l][sz] = min(
    cost(l, l + sz - 1) + dp[l + sz][1],
    dp[l][sz + 1]
)

- Ranges 3:
[[[x] [x]] [[x x] [x]]] x x x x x x x x
dp[l][r] =

  for  md :
      dp[l][md] + dp[md + 1][r]


- Counting (Inclusion & Exclusion)
    - Coin change

- Printing

- in some problems memset() takes a lot of time so we use vis[] and an id for reach testcase instead.

 */

//// 0/1 dp example
ll n, k, mem[101][100005];
vector<ll> a, b;

ll rec(int i, ll sum) {
    if (i == n)
        return (!sum) ? 0 : -1e11;

    if (mem[i][sum] != -1)
        return mem[i][sum];

    ll ret = rec(i + 1, sum); // leave.
    ret = max(ret, rec(i + 1, sum + a[i] - k * b[i]) + a[i]); // pick.

    return mem[i][sum] = ret;
}

//// dp mask
//// traveling salesman problem
int rec(int man, int mask) {
    if (man == n)
        return 1;

    if (dp[mask] != -1)
        return dp[mask];

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (mask >> i & 1) continue; // if the women is taken.
        if (v[man][i] == 0) continue;
        ret = (ret + rec(man + 1, mask | (1 << i))) % mod;
    }
    return dp[mask] = ret;
}


//// dp digit
ll rec(int i, int sum, int f1, int f2) {
    if (i == n)
        return sum == 0;

    if (dp[i][sum][f1][f2] != -1)
        return dp[i][sum][f1][f2];

    int s = a[i] - '0', e = b[i] - '0';
    if (f1) e = 9;
    if (f2) s = 0;

    ll ret = 0;
    for (int j = s; j <= e; ++j) {
        if (i % 2 and j != d) continue;
        if (i % 2 == 0 and j == d) continue;
        ret = add(ret,
                  rec(i + 1,
                      (sum % m + mul(j, powers[i])) % m,
                      f1 or j < (b[i] - '0'),
                      f2 or j > (a[i] - '0')));
    }

    return dp[i][sum][f1][f2] = ret;
}

