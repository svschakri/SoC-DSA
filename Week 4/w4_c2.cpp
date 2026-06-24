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
    string s;
    cin>>s;
    int k=0;
    if (n%2==1){
        loop(0,3){
            cout<<s[k];
            k++;
        }
        if(n!=3)cout<<'-';
    }
    for(;k<n;k+=2){
        cout<<s[k]<<s[k+1];
        if(k+2<n) cout<<'-';
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();

    return 0;
}