#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
const int INF = 1e18;
const int MOD = 998244353;



void solve() {
    int n;
    cin>>n;

    vi v(n);
    input(v,n);

    vi ma(n),mi(n),vma(n),vmi(n);


    mi[0]=v[0];
    ma[0]=abs(v[0]);
    vma[0]=vmi[0]=1;
    if(ma[0]==mi[0]){
        vma[0]++;vmi[0]++;
    }
    loop(1,n){
        ma[i]=max(abs(v[i]+ma[i-1]),abs(v[i]+mi[i-1]));        
        mi[i]=min((v[i]+ma[i-1]),(v[i]+mi[i-1]));

        if(ma[i]==v[i]+ma[i-1]) vma[i]+=vma[i-1];
        if(ma[i]==v[i]+mi[i-1] and ma[i-1]!=mi[i-1]) vma[i]+=vmi[i-1];
        if(ma[i]==abs(v[i]+ma[i-1])) vma[i]+=vma[i-1];
        if(ma[i]==abs(v[i]+mi[i-1]) and ma[i-1]!=mi[i-1]) vma[i]+=vmi[i-1];
        
        if(mi[i]==v[i]+ma[i-1]) vmi[i]+=vma[i-1];
        if(mi[i]==v[i]+mi[i-1] and ma[i-1]!=mi[i-1]) vmi[i]+=vmi[i-1];
        if(mi[i]==abs(v[i]+ma[i-1])) vmi[i]+=vma[i-1];
        if(mi[i]==abs(v[i]+mi[i-1]) and ma[i-1]!=mi[i-1]) vmi[i]+=vmi[i-1];

        vma[i]%=MOD;
        vmi[i]%=MOD;

    }

    cout<<vma[n-1]<<'\n';

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