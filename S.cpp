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

string k;
ll d;
long dp[10001][101][2];

ll solve(ll ind, ll mod, ll flag)
{
    if (ind >= k.size())
        return (mod == 0);

    if (dp[ind][mod][flag] != -1)
        return dp[ind][mod][flag];

    ll res = 0, dig = k[ind] - '0', i = 0;
    if (flag == 0)
        dig = 10;
    while (i < dig)
    {
        res += solve(ind + 1, (mod + i) % d, 0);
        ++i;
        res %= MOD;
    }

    if (flag == 1)
        res += solve(ind + 1, (mod + i) % d, 1);

    return dp[ind][mod][flag] = res % MOD;
}

signed main()
{
    fastIO;
    mem(dp, -1);
    cin >> k >> d;
    cout << (solve(0, 0, 1) - 1 + MOD) % MOD;
    return 0;
}