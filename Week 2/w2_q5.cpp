#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

void solve() {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int l=0,r=0;
    for(int i=0;i<n;i++){
        l+=abs(v[i]-v[n/2]);
        r+=abs(v[i]-v[(n-1)/2]);
    }
    cout<<min(r,l)<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}