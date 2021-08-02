#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, val, sizeof(ar))
#define fi first
#define se second
#define pb push_back
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.precision(12);

typedef long long ll;
typedef pair<long, long> pll;
typedef pair<ll, ll> plll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vl> vvl;
typedef vector<vll> vvll;

const double PI = 3.141592653589793238;
const ll oo = 1e18;

ll bit[2 * N], dp[2 * N];
ll n, h[2 * N], a[2 * N];

void update(int x, ll val)
{
    while (x <= n)
    {
        bit[x] = max(bit[x], val);
        x += ((x) & (-x));
    }
}

ll query(int x)
{
    ll ans = 0;
    while (x > 0)
    {
        ans = max(ans, bit[x]);
        x -= ((x) & (-x));
    }
    return ans;
}

void solution()
{
    cin >> n;
    fo(i, 1, n + 1) cin >> h[i];
    fo(i, 1, n + 1) cin >> a[i];

    fo(i, 1, n + 1)
    {
        dp[i] = query(h[i] - 1) + a[i];
        update(h[i], dp[i]);
    }

    ll res = 0;
    fo(i, 1, n + 1) res = max(res, dp[i]);
    cout << res;
}

signed main()
{
    fastIO;
    solution();
    return 0;
}