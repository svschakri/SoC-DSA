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
    int n,temp;
    cin>>n;
    temp=n;
    int len=0;
    while(temp){
        len++;
        temp/=10;
    }
    if(n>=(pow(10,len-1)-1)*10/9 and n<=(pow(10,len-1)-1)*2){
        int x=(pow(10,len-1)-1)*10/9;
        int t=n-x;
        while(t){
            if(t%10==9){
                cout<<"NO\n";
                return;
            }
            t/=10;
        }
        cout<<"YES\n";
    }
    else cout<<"NO\n";

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