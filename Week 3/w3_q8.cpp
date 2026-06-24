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
    vi v(n);
    input(v,n);
    vi b=v;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    vi prev(b.size());
    prev[0]=abs(v[0]-b[0]);
    for(int j=1;j<b.size();j++){
        prev[j]=min(prev[j-1],abs(v[0]-b[j]));
    }
    for(int i=1;i<n;i++){
        vi now(b.size());
        now[0]=prev[0]+abs(v[i]-b[0]);
        for(int j=1;j<n;j++){
            now[j]=min(prev[j]+abs(v[i]-b[j]),now[j-1]);
        }
        prev=now;
    }
    cout<<prev[b.size()-1]<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}