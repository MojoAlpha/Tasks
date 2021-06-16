#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000005
#define O 1000000007
#define vi vector<int>
#define vl vector<long>
#define vb vector<bool>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long, long>
#define fo(i, N) for (long i = 0; i < N; ++i)
#define fos(i, b, N) for (long i = b; i < N; ++i)
#define forr(i, N) for (long i = N; i >= 0; --i)
const double PI = 3.141592653589793238;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

int main()
{
    ll n, W, V = 0;
    cin >> n >> W;
    vll w(n), v(n);
    fo(i, n) cin >> w[i] >> v[i];
    fo(i, n) V += v[i];

    ll dp[V + 1];
    memset(dp, 2 * O, sizeof(dp));
    dp[0] = 0;

    for(long i = 0; i < n; ++i) {
        for(long j = V; j >= v[i]; --j)
            dp[j] = min(dp[j], w[i] + dp[j - v[i]]);
    }

    long i = V;

    while(dp[i] > W)
        i--;
    cout << i;
    return 0;
}