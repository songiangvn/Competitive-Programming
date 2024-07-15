#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for (int i = 0; i <= 5; i++)
            for (int j = 0; j <= 5 - i; j++)
                for (int k = 0; k <= 5 - i - j; k++)
                    ans = max(ans, (a + i) * (b + j) * (c + k));
        cout << ans << '\n';
    }
    return 0;
}