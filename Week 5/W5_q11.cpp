#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v) for(int i=0;i<v.size();i++) cin>>v[i]
const int INF = 1e18;
const int MOD = 1e9+7;

int modpow(int a,int b,int mod){
    if(a<=1) return a;
    if(b==0) return 1;
    a=a%mod;
    if((b&1)==1) return (a*modpow(a,b-1,mod))%mod;
    return modpow((a*a)%mod,b/2,mod);
}
void solve() {
    int n;
    cin>>n;
    vi v(n+1);
    loop(0,n+1) cin>>v[i];
    int tot=0;
    vi fac(v[0]+n+5);
    vi inverse(v[0]+n+5);
    vi infac(v[0]+n+5);
    loop(2,v[0]+n+5){
        inverse[i]=modpow(i,MOD-2,MOD);
    }
    infac[0]=fac[0]=fac[1]=infac[1]=1;
    fac[2]=2;
    infac[2]=inverse[2];
    loop(3,v[0]+n+5){
        fac[i]=(fac[i-1]*i)%MOD;
        infac[i]=(infac[i-1]*inverse[i])%MOD;
    }
    for(int i=0;i<=n;i++){
        if(v[i]<=0)break; 
        tot+=(((fac[v[i]+i]*infac[i+1])%MOD)*infac[v[i]-1])%MOD;
        tot%=MOD;
    }
    cout<<tot<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();

    return 0;
}