#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
const int INF = 1e18;

void solve() {
    int n,w;
    cin>>n>>w;
    vector<pi> v(n);
    int tot_v=0;

    loop(0,n){
        cin>>v[i].first>>v[i].second;
        tot_v+=v[i].second;
    }
        
    vvi dp(n+1,vi(tot_v+1));
    loop(0,tot_v+1){
       dp[0][i]=INF;
    }

    dp[0][0]=0;
    
    loop(1,n+1){
        pi weight=v[i-1];
        for(int j=0;j<tot_v+1;j++){
            dp[i][j]=dp[i-1][j];
            if(j-v[i-1].second>=0){
                dp[i][j]=min(dp[i][j],dp[i-1][j-v[i-1].second]+v[i-1].first);
            }
        }
    }
    for(int j=tot_v;j>-1;j--){
        if(dp[n][j]<=w){
            cout<<j<<'\n';
            break;
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

 
        solve();

    return 0;
}