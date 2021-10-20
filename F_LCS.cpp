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
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
              dp[i][j]=1+dp[i-1][j-1];
            } else{
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    // cout<<dp[n][m]<<"\n";
    int i=n,j=m;
    string ans;
    while(i>=1 && j>=1){
        if(s[i-1]==t[j-1]){
           ans+=s[i-1];
           i--;
           j--;
        }
        else{
            if(i>=1 && dp[i][j]==dp[i-1][j]){
                 i--; 
            }
            else if(j>=1 && dp[i][j]==dp[i][j-1]){
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";

}
