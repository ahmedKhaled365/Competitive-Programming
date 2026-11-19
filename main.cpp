#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define Ahmed cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), \
cout.sync_with_stdio(0);
#define ll long long
#define ld long double
#define int ll
#define all(v) v .begin(), v.end()
#define allRev(v) v.rbegin(), v.rend()
#define el '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define popcnt(n) __builtin_popcount(n)

#define ordered_set tree<ll, null_type,less<ll>, \
rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll, null_type, less_equal<ll>, rb_tree_tag, \
tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

//const ll mod = 998244353;
const ll mod = 1e9 + 7;
// const ll mod = 104206969;
const int N = 3e5 + 10, Log = 20, SQ = 224;
const ll inf = 1e18, neg = -1e18;
const double pi = 3.14159265358979323846;
char direction[4] = {'R', 'L', 'D', 'U'};
int di[8] = {0, +0, 1, -1, -1, -1, +1, 1};
int dj[8] = {1, -1, 0, +0, -1, +1, -1, 1};

void start() {
    Ahmed
    //    cout << fixed << setprecision(18);
    //    cin.ignore();
    //    getline(cin, variable);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

void solve() {

}

int32_t main() {
    start();

    int t = 1;
    //    cin >> t;

    while (t--)
        solve();
}
