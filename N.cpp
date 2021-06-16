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

ll n;
ll a[500];
ll dp[500][500];

ll solution(ll i, ll j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    ll tmp = oo;
    for (long k = i + 1; k <= j; ++k)
    {
        ll t1 = a[k - 1], t2 = a[k];
        a[k - 1] = a[k] = (t1 + t2);
        tmp = min(tmp, t1 + t2 + solution(i, k - 1) + solution(k, j));
        a[k - 1] = t1;
        a[k] = t2;
    }
    return dp[i][j] = tmp;
}

signed main()
{
    fastIO;
    mem(dp, -1);
    cin >> n;
    fo(i, 0, n) cin >> a[i];
    cout << solution(0, n - 1);
    return 0;
}