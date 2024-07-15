#include <bits/stdc++.h>

using namespace std;

pair<int, int> dp[(int)2e5 + 5];

pair<int, int> getBest(pair<int, int> x, pair<int, int> y)
{
    if (x.first > y.first)
        return x;
    if (x.first < y.first)
        return y;
    if (x.second < y.second)
        return x;
    return y;
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        s = 'L' + s;
        s = s + 'L';
        for (int i = 0; i <= n + 1; i++)
            dp[i] = make_pair(0, 0);
        dp[0] = make_pair(1, 0);
        for (int i = 0; i <= n; i++)
            if (dp[i].first == 1)
            {
                if (s[i] == 'L')
                {
                    for (int j = 1; j <= m; j++)
                        if (i + j <= n + 1 && s[i + j] != 'C')
                        {
                            if (s[i + j] == 'L')
                                dp[i + j] = getBest(dp[i + j], dp[i]);
                            else if (dp[i].second + 1 <= k)
                                dp[i + j] = getBest(dp[i + j], make_pair(1, dp[i].second + 1));
                        }
                }
                if (s[i + 1] != 'C')
                {
                    if (s[i + 1] == 'L')
                        dp[i + 1] = getBest(dp[i + 1], dp[i]);
                    else if (dp[i].second + 1 <= k)
                        dp[i + 1] = getBest(dp[i + 1], make_pair(1, dp[i].second + 1));
                }
            }
        cout << (dp[n + 1].first == 1 ? "YES\n" : "NO\n");
    }
    return 0;
}