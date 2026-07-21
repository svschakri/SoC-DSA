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
    int n,k;
    cin>>n>>k;
    vi v(n);
    input(v);
    int ma=-2*k*n;
    for(int i=max(n-2*k,1LL);i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            ma=max(ma,i*j-k*(v[i-1]|v[j-1]));
        }
    }    
    cout<<ma<<'\n';
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