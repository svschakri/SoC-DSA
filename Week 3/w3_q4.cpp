#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vs vector<string>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
const int INF = 1e18;

void solve() {
    string s1,s2;
    cin>>s1>>s2;
    if(s1.size()<s2.size()){
        string temp=s2;
        s2=s1;
        s1=temp;
    }
    int dp[s1.size()+1][s2.size()+1];
    dp[0][0]=0;
    loop(1,s2.size()+1) dp[0][i]=i;
    loop(1,s1.size()+1) dp[i][0]=i;
    dp[1][1]=min(abs(s1[0]-s2[0]),1);
    loop(1,s1.size()+1){
        for(int j=1;j<s2.size()+1;j++){
            dp[i][j]=min(dp[i][j-1],dp[i-1][j])+1;
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+min(abs(s1[i-1]-s2[j-1]),1));
        }
    }
    cout<<dp[s1.size()][s2.size()]<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}