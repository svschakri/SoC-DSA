#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

void solve() {
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i+1;
    }
    sort(v.begin(),v.end());
    int lm=0,l=0,mid=0,r=n-1;
    while(lm<n-3){
        l=lm+1;
        while(l<n-2){
            mid=l+1;r=n-1;
            while(mid<r){
                if(v[mid].first+v[r].first==x-v[l].first-v[lm].first){
                    cout<<v[lm].second<<' '<<v[l].second<<' '<<v[mid].second<<' '<<v[r].second<<'\n';
                    return;
                }
                else if(v[mid].first+v[r].first<x-v[l].first-v[lm].first) mid++;
                else if(v[mid].first+v[r].first>x-v[l].first-v[lm].first) r--;
            }
            l++;
        }
        lm++;
    }
    cout<<"IMPOSSIBLE\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}