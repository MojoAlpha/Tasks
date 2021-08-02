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

unordered_map<ll, bool> mp;
ll n, dp[3005][3005];
string s;

ll solve(ll pos, ll val)
{
    if (pos >= n - 1)
        return 1;

    if (dp[pos][val] != -1)
        return dp[pos][val];

    ll res = 0;
    if (s[pos] == '>')
    {
        for (ll i = val - 1; i > 0; --i)
        {
            if (mp[i] == 0)
            {
                mp[i] = 1;
                res = (res + solve(pos + 1, i)) % MOD;
                mp[i] = 0;
            }
        }
    }
    else
    {
        for (ll i = val + 1; i <= n; ++i)
        {
            if (mp[i] == 0)
            {
                mp[i] = 1;
                res = (res + solve(pos + 1, i)) % MOD;
                mp[i] = 0;
            }
        }
    }
    return dp[pos][val] = res;
}

signed main()
{
    fastIO;
    ll res = 0;
    mem(dp, -1);
    cin >> n >> s;

    fo(i, 1, n + 1)
    {
        mp[i] = 1;
        res += solve(0, i);
        res %= MOD;
        mp[i] = 0;
    }

    cout << res;
    return 0;
}