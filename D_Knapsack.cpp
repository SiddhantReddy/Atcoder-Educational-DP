#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

ll weight[101],value[101];
ll dp[101][100005];

// ll best_value(int N,int W){
//     if(N==-1){
//         return 0;
//     }
//     if(W==0){
//         dp[N][W]=0;
//         return dp[N][W];
//     }
//     if(dp[N][W]!=-1){
//         return dp[N][W];
//     }
//     ll take=0;
//     if(weight[N]<=W){
//       take=best_value(N-1,W-weight[N])+value[N];
//     }
//     ll dont_take=best_value(N-1,W);
//     dp[N][W]=max(take,dont_take);
//     return dp[N][W];
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n,w;
    cin >> n>>w;
    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<w;j++){
            dp[i][j]=-1;
        }
    }
    // cout<<best_value(n-1,w);

    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else{
                ll dont_pick=dp[i-1][j];
                ll pick=0;
                if(weight[i-1]<=j){
                    pick=dp[i-1][j-weight[i-1]]+value[i-1];
                }
                dp[i][j]=max(pick,dont_pick);
            }
        }
    }
    cout<<dp[n][w];
    return 0;
}
