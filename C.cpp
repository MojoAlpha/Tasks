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
    long n;
    cin >> n;
    long a[n][3];
    fo(i, n) cin >> a[i][0] >> a[i][1] >> a[i][2];
    long dp[n + 1][3];
    dp[1][0] = a[0][0];
    dp[1][1] = a[0][1];
    dp[1][2] = a[0][2];

    for(long i = 2; i < n + 1; ++i) {
        dp[i][0] = a[i - 1][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = a[i - 1][1] + max(dp[i - 1][2], dp[i - 1][0]);
        dp[i][2] = a[i - 1][2] + max(dp[i - 1][1], dp[i - 1][0]);
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]});
    return 0;
}