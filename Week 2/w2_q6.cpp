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
    int n;
    cin>>n;
    vi pos(n+1);
    loop(0,n){
        int temp;
        cin>>temp;
        pos[temp]=i;
    }
    int l=(n+1)/2,r=(n+2)/2;
    while(l>0 and r<n+1 and (l==r or (pos[l]<pos[r] and pos[l]<pos[l+1] and pos[r-1]<pos[r]))){
        l--;r++;
    }
    cout<<(n-(r-l)+1)/2<<'\n';
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