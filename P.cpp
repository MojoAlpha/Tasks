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

vi gr[N];
ll n, a, b, dp[N][2];

ll solve(int v, int c, int p)
{
    if (dp[v][c] != -1)
        return dp[v][c];

    ll tot = 1;
    for (auto u : gr[v])
    {
        if (u == p)
            continue;
        if (c == 0)
            tot = (tot * (solve(u, 0, v) + solve(u, 1, v) % MOD) % MOD) % MOD;
        else
            tot = (tot * solve(u, 0, v)) % MOD;
    }
    return dp[v][c] = tot;
}

signed main()
{
    fastIO;
    mem(dp, -1);

    cin >> n;
    fo(i, 0, n - 1)
    {
        cin >> a >> b;
        gr[a].pb(b);
        gr[b].pb(a);
    }

    cout << (solve(1, 0, -1) + solve(1, 1, -1)) % MOD;

    return 0;
}