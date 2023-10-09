#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main()
{
    int t;
    cin >> t;
    const int N = 1e5 + 7;
    vector<int> a;
    while (t--)
    {
        int n;
        cin >> n;
        if (!(n % 3) || n <= 3)
        {
            cout << "NO" << endl;
            continue;
        }
        int x = 1;
        int y = 2;
        int z = n - 3;
        while (x == y || y == z || x == z || x % 3 == 0 || y % 3 == 0 || z % 3 == 0)
        {
            x++;
            y++;
            z--;
        }
        if (z <= 0 || x >= n || y >= n)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << x << " " << y << " " << z << endl;
    }
}