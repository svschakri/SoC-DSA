#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

void solve() {
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int sum=0,right=t*v[0],left=1,ans=0;
    while(right>left){
        sum=0;
        int mid=left+(right-left)/2;
        for(auto val:v){
            sum+=mid/val;
        }
        if (sum<t){
            left=mid+1;
        }
        else {
            right=mid;
            ans=right;
        }
    }
    if(left==right){
        sum=0;
        for(auto val:v){
            sum+=left/val;
        }
        if(sum>=t) ans=left;
    }    
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}