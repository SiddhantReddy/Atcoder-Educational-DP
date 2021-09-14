#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

vector<int> dp;
vector<int> dp1;

// Recursive Approach
int solveRecursive(int n, vector<int> &arr)
{
    if (dp[n] != -1)
        return dp[n];
    if (n == 0)
        return dp[0]=0;
    if (n == 1)
        return dp[n] = abs(arr[1] - arr[0]);

    int first_jump = solveRecursive(n - 1,arr) + abs(arr[n - 1] - arr[n]);
    int second_jump = solveRecursive(n - 2,arr) + abs(arr[n - 2] - arr[n]);
    dp[n] = min(first_jump, second_jump);
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

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Recursive approach
    dp.resize(n, -1);
    cout << solveRecursive(n - 1, arr) << "\n";

    // Iterative approach
    // dp1.resize(n);
    // dp1[0]=0;
    // dp1[1]=abs(arr[1]-arr[0]);
    // for(int i=2;i<n;i++){
    //     dp1[i]=min(dp1[i-1]+abs(arr[i-1]-arr[i]),dp1[i-2]+abs(arr[i-2]-arr[i]));
    // }
    // cout<<dp1[n-1]<<"\n";

    // More Optimized -> No need for extra space
    int previous_to_previous=0;
    int previous=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        int curr=min(previous+abs(arr[i-1]-arr[i]),previous_to_previous+abs(arr[i-2]-arr[i]));
        previous_to_previous=previous;
        previous=curr;
    }
    cout<<previous<<"\n";

    return 0;
}
