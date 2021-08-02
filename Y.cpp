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

ll h, w, n, fact[2 * N];

ll binPow(ll a, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

ll inverse(ll a)
{
    if (a <= 1)
        return 1;
    return binPow(a, MOD - 2);
}

ll pathsPassingPoint(ll r, ll c)
{
    ll p1 = (fact[r + c - 2] * inverse((fact[r - 1] * fact[c - 1]) % MOD)) % MOD;
    ll p2 = (fact[h + w - r - c] * inverse((fact[h - r] * fact[w - c]) % MOD)) % MOD;

    return (p1 * p2) % MOD;
}

signed main()
{
    fastIO;
    ll row, col;
    fact[0] = fact[1] = 1;
    fo(i, 2, 2 * N) fact[i] = (fact[i - 1] * i) % MOD;

    cin >> h >> w >> n;

    ll res = pathsPassingPoint(h, w);
    fo(i, 0, n)
    {
        cin >> row >> col;
        ll paths = pathsPassingPoint(row, col);
        res = (res + MOD - paths) % MOD;
    }
    cout << res;
    return 0;
}