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

ll n, k;

void matMultiply(vvl &a, vvl m1, vvl m2)
{
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            a[i][j] = 0;
            fo(k, 0, n)
            {
                a[i][j] += m1[i][k] * m2[k][j];
                a[i][j] %= MOD;
            }
        }
    }
}

vvl matPow(vvl a, ll k)
{
    vvl res(n, vl(n, 0));
    fo(i, 0, n) res[i][i] = 1;

    while (k)
    {
        if (k & 1)
            matMultiply(res, res, a);
        matMultiply(a, a, a);
        k >>= 1;
    }
    return res;
}

signed main()
{
    fastIO;
    cin >> n >> k;
    vvl a(n, vl(n));
    fo(i, 0, n) fo(j, 0, n) cin >> a[i][j];

    vvl res = matPow(a, k);
    ll ans = 0;

    for (auto &i : res)
        for (auto &j : i)
            ans = (ans + j) % MOD;

    cout << ans;
    return 0;
}