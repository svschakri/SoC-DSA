#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
const int INF = 1e18;
const int MOD =1e9+7;

void solve() {
    int t,ma=0;
    cin>>t;
    vi v(t);
    loop(0,t){
        cin>>v[i];
        ma=max(ma,v[i]);
    }

    int n;
    n=ma;
    vector<vi>dp(n+1,vi(2));
    dp[1][0]=1;
    dp[1][1]=1;
    loop(2,n+1){
        dp[i][0]=((dp[i-1][1])%MOD+(dp[i-1][0]*4)%MOD)%MOD;
        dp[i][1]=((dp[i-1][1]*2)%MOD+dp[i-1][0])%MOD;
    }
    for(auto a:v){
        cout<<(dp[a][0]+dp[a][1])%MOD<<"\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}