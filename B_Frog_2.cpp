#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

vector<int> dp;

// Recursive Approach
int solveRecursive(int n,int k ,vector<int> &arr)
{
    if (dp[n] != -1)
        return dp[n];
    if (n == 0)
        return dp[0]=0;
    int ans=1e9;
    for(int jump_size=1;jump_size<=k;jump_size++){
        if(n-jump_size>=0){
            ans=min(ans,solveRecursive(n-jump_size,k,arr)+abs(arr[n]-arr[n-jump_size]));
        }
    }
    dp[n] = ans;
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n,k;
    cin >> n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Recursive approach
    dp.resize(n, -1);
    cout << solveRecursive(n - 1, k, arr) << "\n";

    return 0;
}
