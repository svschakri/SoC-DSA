#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v) for(int i=0;i<v.size();i++) cin>>v[i]
const int INF = 1e18;

void solve() {
    int a,b;
    cin>>a>>b;
    int ans=INF;
    for(int i=1;i<sqrt((a+b)*2);i++){
        ans=min(ans,(a+i-1)/i+(b+i-1)/i+i-1);
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}