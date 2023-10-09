#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<set<int>> S(n + 1);
        vector<int> numSet;
        int a[51]{};
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                int x;
                cin >> x;
                S[i].insert(x);
                if (!a[x])
                    numSet.push_back(x);
                a[x] = 1;
            }
        }
        int res = 0;
        for (auto i : numSet)
        {
            set<int> u;
            for (auto s : S)
            {
                if (s.find(i) == s.end())
                {
                    u.insert(s.begin(), s.end());
                }
            }
            res = max(res, int(u.size()));
        }
        cout << res << endl;
    }
}