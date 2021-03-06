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
ll pre[500];
ll dp[500][500];

ll solution(ll l, ll r)
{
    if (l >= r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    ll res = oo;
    for (ll i = l; i < r; ++i)
    {
        ll left = solution(l, i), right = solution(i + 1, r);
        ll tmp = left + right + pre[i] - pre[l - 1] + pre[r] - pre[i];
        res = min(res, tmp);
    }
    return dp[l][r] = res;
}

signed main()
{
    fastIO;
    mem(dp, -1);
    mem(pre, 0);
    cin >> n;
    fo(i, 1, n + 1) cin >> a[i];
    fo(i, 1, n + 1) pre[i] = pre[i - 1] + a[i];

    cout << solution(1, n);
    return 0;
}