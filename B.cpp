#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        for (int i = 1; i <= k; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = 0; i < a.size() - 1; i++)
        {
            ans += a[i] + a[i] - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}