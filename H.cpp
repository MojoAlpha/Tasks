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
    long h, w;
    cin >> h >> w;
    vector<string> s(h);
    fo(i, h) cin >> s[i];

    ll dp[h + 1][w + 1];
    memset(dp, 0, sizeof(dp));
    fo(i, h + 1) dp[i][0] = 0;
    fo(i, w + 1) dp[0][i] = 0;
    dp[1][1] = 1;
    
    for(long i = 1; i < h + 1; ++i) {
        for(long j = 1; j < w + 1; ++j) {
            if(s[i - 1][j - 1] == '.')
                dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            else
                dp[i][j] = 0;
        }
    }

    cout << dp[h][w];
    return 0;
}