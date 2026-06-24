#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
const int INF = 1e18;

void solve() {
    int n;
    cin>>n;
    vector<vi> v(n,vi(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    int t;
    cin>>t;
    while(t--){
        int x,y,d;
        cin>>x>>y>>d;
    
        v[x-1][y-1]=v[y-1][x-1]=min(d,v[x-1][y-1]);

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                v[i][j]=v[j][i]=min(min(v[i][j],v[i][x-1]+v[x-1][y-1]+v[y-1][j]),v[i][y-1]+v[x-1][y-1]+v[x-1][j]);
                ans+=v[i][j];
            }
        }
        cout<<ans<<' ';

    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();

    return 0;
}