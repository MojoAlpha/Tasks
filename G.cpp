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
    cin.tie(NULL);

typedef long long ll;
typedef pair<long, long> pll;
typedef pair<ll, ll> plll;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef set<long>::iterator sit;
typedef map<long, long>::iterator mit;
typedef vector<long>::iterator vit;

const double PI = 3.141592653589793238;
const ll oo = 1e18;

ll dp[N];
ll n, m;
vl adj[N];

ll dfs(ll v)
{
    if (dp[v] != -1)
        return dp[v];

    dp[v] = 0;
    ll val = -1;
    for (auto i : adj[v])
        val = max(val, dfs(i));
    return dp[v] = 1 + val;
}

void solution()
{
    mem(dp, -1);
    ll a, b;
    cin >> n >> m;
    fo(i, 0, m)
    {
        cin >> a >> b;
        adj[a].pb(b);
    }
    fo(i, 1, n + 1)
    {
        if (dp[i] == -1)
            dfs(i);
    }

    cout << *max_element(dp, dp + N);
}

signed main()
{
    fastIO;
    solution();
    return 0;
}