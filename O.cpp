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

const int MAXN = 21;
const int MAXL = (1 << 21) + 2;
int n, dp[MAXN][MAXL], mas[MAXN];

int solution(int pos, int bitmasks)
{
    if (pos == n)
        return (__builtin_popcount(bitmasks) == n);

    if (dp[pos][bitmasks] != -1)
        return dp[pos][bitmasks];

    int tot = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!(bitmasks & (1 << i)) && ((1 << i) & mas[pos]))
            tot = (tot + solution(pos + 1, bitmasks | (1 << i))) % MOD;
    }
    return dp[pos][bitmasks] = tot;
}

signed main()
{
    fastIO;
    mem(dp, -1);
    cin >> n;
    int x;
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            cin >> x;
            if (x)
                mas[i] |= (1 << j);
        }
    }
    cout << solution(0, 0);
    return 0;
}