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
    ll n, W;
    cin >> n >> W;
    vll w(n), v(n);
    fo(i, n) cin >> w[i] >> v[i];
    ll dp[n + 1][W + 1];
    fo(i, n + 1) dp[i][0] = 0;
    fo(i, W + 1) dp[0][i] = 0;

    for(long i = 1; i < n + 1; ++i) 
    {
        for(long j = 1; j < W + 1; ++j)
        {
            if(j >= w[i - 1])
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][W];
    return 0;
}