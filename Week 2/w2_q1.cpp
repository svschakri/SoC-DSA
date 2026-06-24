#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    multiset<int> window;
    for(int i=0;i<n;i++) cin>>v[i];
    int l=0,r=0,ma=0;
    while(r<n){
        window.insert(v[r]);
        if(window.count(v[r])==1)ma=max(ma,r-l);
        while(window.count(v[r])>1){
            window.erase(window.find(v[l]));
            l++;
        }
        if(window.count(v[r])==1)ma=max(ma,r-l);
        r++;
    }
    ma=max(ma,r-l-1);
    cout<<ma+1<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}