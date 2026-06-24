#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
const int INF = 1e18;

void solve() {
    int n,p1,p2,p3,t1,t2;
    cin>>n>>p1>>p2>>p3>>t1>>t2;
    vi start(n),end(n);
    loop(0,n) cin>>start[i]>>end[i];
    int sum=0;
    loop(0,n) sum+=(end[i]-start[i])*p1;
    loop(1,n){
        int timediff=start[i]-end[i-1];
        if(timediff<=t1){
            sum+=timediff*p1;
        }
        else if(timediff<=t1+t2){
            sum+=t1*p1;
            sum+=(timediff-t1)*p2;
        }
        else{
            sum+=t1*p1;
            sum+=t2*p2;
            sum+=(timediff-t1-t2)*p3;
        }
    }
    cout<<sum<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();

    return 0;
}