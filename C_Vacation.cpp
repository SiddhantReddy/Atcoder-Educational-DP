#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }
    int x = a[0], y = b[0], z = c[0];
    for (int i = 1; i < n; i++)
    {
        // cout << x << " " << y << " " << z << "\n";
        int nx = a[i] + max(y, z);
        int ny = b[i] + max(x, z);
        int nz = c[i] + max(y, x);
        x = nx;
        y = ny;
        z = nz;
    }
    cout << max({x, y, z});
    return 0;
}
