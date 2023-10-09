#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;
int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        ll pos;
        cin >> s >> pos;
        ll n = s.size(), totalLen = 0, curItem = s.size();
        for (ll i = n; i >= 0; i--)
        {
            totalLen += i;
            if (pos <= totalLen)
            {
                curItem = i;
                break;
            }
        }
        ll commonLen = totalLen - curItem;
        ll idx = pos - commonLen;
        ll rm = n - curItem;

        string stk = "a";
        for (ll i = 0; i < n; i++)
        {
            while (s[i] < stk.back() && rm > 0)
            {
                rm--;
                stk.pop_back();
            }
            stk += s[i];
        }
        cout << stk[idx];
    }
}