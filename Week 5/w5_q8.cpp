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
    int n,m;
    cin>>n>>m;
    vi v(n);
    loop(0,n){//n
        cin>>v[i];
        v[i]%=m;
    }
    if(n>=m){
        cout<<"YES\n";
        return;
    }
    vector<vector<bool>> can(n,vector<bool>(m,false));
    can[0][v[0]]=true;
    for(int i=1;i<n;i++){
        can[i][v[i]]=true;
        for(int j=0;j<m;j++){
            if(!can[i-1][j]) continue;
            can[i][j]=true;
            can[i][(j+v[i])%m]=true;
        }
    }
    if(can[n-1][0]){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();

    return 0;
}