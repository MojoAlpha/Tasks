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

ll dp[N];
ll n, k, a[105];

ll solution(ll k)
{
    if (dp[k] != -1)
        return dp[k];
    if (k == 0)
        return dp[k] = 0;

    ll ans = 0;
    for (long i = 1; i <= n; ++i)
    {
        if (a[i] > k)
            continue;
        if (solution(k - a[i]) == 0)
        {
            ans = 1;
            break;
        }
    }
    return dp[k] = ans;
}

signed main()
{
    fastIO;
    mem(dp, -1);
    cin >> n >> k;
    fo(i, 0, n) cin >> a[i + 1];
    if (solution(k))
        cout << "First\n";
    else
        cout << "Second\n";
    return 0;
}