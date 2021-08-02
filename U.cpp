#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, (val), sizeof(ar))
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
const ll V = (1 << 18) + 2;

ll n, a[18], dp[18][V];

ll solve(ll pos, ll bitmask)
{
    if (pos >= n)
        return -oo;

    if (dp[pos][bitmask] != -1)
        return dp[pos][bitmask];

    ll res = -oo;
    fo(i, 0, pos)
    {
        if (i == ind)
    }
}

signed main()
{
    fastIO;
    mem(dp, -1);

    cin >> n;
    fo(i, 0, n) fo(j, 0, n) cin >> a[i][j];

    cout << solve(0, 0);
    return 0;
}