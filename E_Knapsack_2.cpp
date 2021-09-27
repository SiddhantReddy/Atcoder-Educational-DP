#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

ll inf = 1e15;
const ll max_val = 100005;

ll weight[101], value[101];
ll dp[101][max_val];

// ll LW(int N, int tot_val)
// {
//     if (N == -1)
//     {
//         if (tot_val > 0)
//             return inf;
//         return 0;
//     }
//     if (tot_val == 0)
//     {
//         return 0;
//     }
//     if(dp[N][tot_val]!=-1){
//         return dp[N][tot_val];
//     }
//     ll take = inf;
//     if (value[N] <= tot_val)
//     {
//         take = LW(N - 1, tot_val - value[N]) + weight[N];
//     }
//     ll dont_take = LW(N - 1, tot_val);
//     dp[N][tot_val] = min(take, dont_take);
//     return dp[N][tot_val];
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    // for (int i = 0; i < 101; i++)
    // {
    //     for (int j = 0; j < max_val; j++)
    //     {
    //         dp[i][j] = -1;
    //     }
    // }

   
    for(ll item=0;item<=n;item++){
        for(ll tot_val=0;tot_val<=max_val;tot_val++){
            if(item==0){
                if(tot_val>0){
                    dp[item][tot_val]=inf;
                }
                else{
                    dp[item][tot_val]=0;
                }
            }
            else{
               ll take=inf;
               if(value[item-1]<=tot_val){
                   take=dp[item-1][tot_val-value[item-1]]+weight[item-1];
               } 
               ll dont_take=dp[item-1][tot_val];
               dp[item][tot_val]=min(take,dont_take);
            }
        }
    }
     ll ans = 0;
    for (ll v = 0; v <= max_val; v++)
    {
        if (dp[n][v]<= w)
        {
            ans = max(ans, v);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
