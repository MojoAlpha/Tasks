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

long n;
double dp[3001][3001], p[3001];
bool vis[3001][3001];

double solution(long pos, long heads)
{
    if (heads < 0)
        return 0.0;
    if (pos == 0)
        return (heads == 0);

    if (vis[pos][heads])
        return dp[pos][heads];
    vis[pos][heads] = true;

    return dp[pos][heads] = (solution(pos - 1, heads - 1) * p[pos] + solution(pos - 1, heads) * (1.0 - p[pos]));
}

signed main()
{
    fastIO;
    cout.precision(15);
    mem(dp, 0);
    mem(vis, false);

    cin >> n;
    fo(i, 1, n + 1) cin >> p[i];
    double res = 0.0;

    for (long heads = 0; heads <= n; ++heads)
    {
        long tails = n - heads;
        if (heads > tails)
            res += solution(n, heads);
    }

    cout << res;
    return 0;
}