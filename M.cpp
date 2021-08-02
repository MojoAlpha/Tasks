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

ll n, k;
ll a[105];
ll dp[105][N];

void solution()
{
    cin >> n >> k;
    fo(i, 0, n) cin >> a[i];

    fo(i, 0, k + 1) dp[0][i] = 1;
    fo(i, 0, n + 1) dp[i][0] = 1;

    for (long i = 1; i <= n; ++i)
    {
        for (long j = 1; j <= k; ++j)
        {
            dp[i][j] = dp[i][j - 1];
            dp[i][j] += dp[i - 1][j];
            if (j - a[i - 1] > 0)
                dp[i][j] -= dp[i - 1][j - a[i - 1] - 1];
            dp[i][j] = (dp[i][j] + MOD) % MOD;
        }
    }

    cout << (dp[n][k] - dp[n][k - 1] + MOD) % MOD;
}

signed main()
{
    solution();
    return 0;
}