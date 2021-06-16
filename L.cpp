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

ll dp[3002][3002];
ll a[3002];

void solution()
{
    long n;
    cin >> n;
    fo(i, 1, n + 1) cin >> a[i];

    for (long si = 2; si <= n + 1; ++si)
        for (long i = 1, j = si - 1; j <= n; ++i, ++j)
        {
            int parity = n + i + j;
            if (parity & 1)
                dp[i][j] = max(a[i] + dp[i + 1][j], a[j] + dp[i][j - 1]);
            else
                dp[i][j] = min(-a[i] + dp[i + 1][j], -a[j] + dp[i][j - 1]);
        }

    cout << dp[1][n];
}

signed main()
{
    fastIO;
    mem(dp, 0);
    solution();
    return 0;
}