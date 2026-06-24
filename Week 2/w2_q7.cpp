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
    int n,k;
    cin>>n>>k;
    k++;
    vi v(n);
    input(v,n);
    vi ans;
    int l=0,r=0;
    int count=0;
    for(int i=0;i<n-1;i++){
        if(v[i]<v[i+1]*2) count++;
        else count=0;
        if(count>=k-1){
            ans.push_back(i-n);
        }
    }
    cout<<ans.size()<<'\n';
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