#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        string sn = to_string(n);
        vector<pair<int, int>> answer;
        answer.clear();
        for (int a = 1; a <= 10000; a++)
        {
            for (int b = max(1, (int)sn.length() * a - 6); b <= min((int)sn.length() * a, 10000); b++)
            {
                // cout << a << " " << b << '\n';
                int res = a * n - b;
                string sres = to_string(res);
                bool check = true;
                int pts = 0;
                for (char c : sres)
                {
                    if (c != sn[pts])
                    {
                        check = false;
                        break;
                    }
                    pts = (pts + 1) % sn.length();
                }
                if (check && sres.size() == sn.size() * a - b)
                    answer.push_back(make_pair(a, b));
            }
        }
        cout << answer.size() << '\n';
        for (pair<int, int> x : answer)
            cout << x.first << " " << x.second << '\n';
    }
    return 0;
}