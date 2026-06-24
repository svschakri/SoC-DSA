#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
const int INF = 1e18;
 
void solve() {
    int n,odd=0,even=0,last_odd,last_even;
    cin>>n;
    vi v(n);
    loop(0,n){
        cin>>v[i];
        if(v[i]%2==0){
            even++;
            last_even=i+1;
        }
        else{
            odd++;
            last_odd=i+1;
        }
    }
    if(even==1){
        cout<<last_even<<'\n';
    }
    else cout<<last_odd<<'\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
        solve();
 
    return 0;
}
