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

void solution()
{
    string a, b;
    cin >> a >> b;
    ll dp[a.size() + 1][b.size() + 1];
    mem(dp, 0);
    fo(i, 1, a.size() + 1)
    {
        fo(j, 1, b.size() + 1)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string res = "";
    ll i = a.size(), j = b.size();

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            res.pb(a[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(all(res));
    cout << res << endl;
}

signed main()
{
    fastIO;
    solution();
    return 0;
}