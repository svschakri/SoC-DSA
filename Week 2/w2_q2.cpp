#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int MOD = 1e9+7;
void solve() {
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> v(n);
    for(int i=1;i<n+1;i++){
        cin>>v[i-1].first;
        v[i-1].second=i;
    }
    sort(v.begin(),v.end());
    int l=0,r=n-1;
    while(l<r){
        if(v[l].first+v[r].first<x) l++;
        else if(v[l].first+v[r].first>x) r--;
        else {
            cout<<v[l].second<<' '<<v[r].second;
            return;
        }
    }
    cout<<"IMPOSSIBLE\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}