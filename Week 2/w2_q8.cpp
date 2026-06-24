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
    scanf("%lld %lld",&n,&k);
    vi v(n);
    loop(0,n){
        scanf("%lld",&v[i]);
    }
    int l=0,r=0;
    int ans=0,ans_l,ans_r;
    multiset<int> win;
    set<int> coun;
    while(r<n){
        win.insert(v[r]);
        coun.insert(v[r]);
        while(coun.size()>k){
            if(win.count(v[l])==1){
                win.erase(v[l]);
                coun.erase(v[l]);
            }
            else{
                win.erase(win.find(v[l]));
            }
            l++;
        }
        if(r-l+1>ans){
            ans=r-l+1;
            ans_l=l;
            ans_r=r;
        }
        r++;
    }
    printf("%lld %lld",ans_l+1,ans_r+1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();

    return 0;
}